#include "surf.h"
#include "extra.h"
#include <math.h>
#include <iostream>
using namespace std;

namespace
{
    
    // We're only implenting swept surfaces where the profile curve is
    // flat on the xy-plane.  This is a check function.
    static bool checkFlat(const Curve &profile)
    {
        for (unsigned i=0; i<profile.size(); i++)
            // if (profile[i].V[2] != 0.0 ||
            //     profile[i].T[2] != 0.0 ||
            //     profile[i].N[2] != 0.0) {
            //     return false;
            // }
            if(profile[i].V[2] != 0.0) return false;
        return true;
    }
}

Surface makeSurfRev(const Curve &profile, unsigned steps)
{
    Surface surface;
    
    // if (!checkFlat(profile))
    // {
    //     cerr << "surfRev profile curve must be flat on xy plane." << endl;
    //     exit(0);
    // }

    // TODO: Here you should build the surface.  See surf.h for details.
    double angle = 2*M_PI/steps;
    // Rotate about y-axis: the transform matrix
    Matrix3f M = Matrix3f((float)cos(angle), 0, (float)sin(angle),
        0, 1, 0,
        (float)(-sin(angle)), 0, (float)cos(angle));
    M.transpose();
    Curve c = profile;
    unsigned num = c.size();
    for(unsigned s = 0; s < steps; s++) {
        Curve newC;
        // Rotate an angle each time step;
        for(unsigned i = 0; i < num; i++) {
            CurvePoint cur = c[i];
            surface.VV.push_back(cur.V);
            surface.VN.push_back(-cur.N);
            Vector3f newV = M*cur.V;
            Vector3f newN = M*cur.N;
            newN.normalize();
            CurvePoint newP = {newV, cur.T, newN, cur.B};
            newC.push_back(newP);
        }
        c = newC;
        newC.clear();
    }
    
    unsigned next;
    for(unsigned s = 0; s < steps; s++) {
        if(s == steps-1) next = 0;
        else next = s+1;
        for(unsigned i = 0; i < num-1; i++) {
            surface.VF.push_back(Tup3u(s*num+i, next*num+i, next*num+i+1));
            surface.VF.push_back(Tup3u(s*num+i, next*num+i+1, s*num+i+1));
        }
    }
    return surface;
}

Matrix4f getTransform(CurvePoint p) {
    Vector4f c1 = Vector4f(p.N, 0);
    Vector4f c2 = Vector4f(p.B, 0);
    Vector4f c3 = Vector4f(p.T, 0);
    Vector4f c4 = Vector4f(p.V, 1);
    return Matrix4f(c1, c2, c3, c4);
}

Surface makeGenCyl(const Curve &profile, const Curve &sweep )
{
    Surface surface;

    if (!checkFlat(profile))
    {
        cerr << "genCyl profile curve must be flat on xy plane." << endl;
        exit(0);
    }

    // TODO: Here you should build the surface.  See surf.h for details.
    Curve c = profile, s = sweep;
    unsigned steps = s.size(), num = c.size();
    for(unsigned i = 0; i < steps; i++) {
        CurvePoint p = s[i];
        Matrix4f transform = getTransform(p);
        Matrix4f transinv = transform.inverse();
        transinv.transpose();
        for(unsigned j = 0; j < num; j++) {
            Vector4f tV = transform*Vector4f(c[j].V, 1);
            Vector4f tN = transinv*Vector4f(c[j].N, 1);
            Vector3f nV = Vector3f(tV[0], tV[1], tV[2]);
            Vector3f nN = Vector3f(-tN[0], -tN[1], -tN[2]);
            nN.normalize();
            surface.VV.push_back(nV);
            surface.VN.push_back(nN);
        }
    }
    unsigned last;
    for(unsigned i = 0; i < steps-1; i++) {
        last = i*num;
        for(unsigned j = 0; j <= num-1; j++) {
            surface.VF.push_back(Tup3u(last+j+1, last+num+j+1, last+num+j));
            surface.VF.push_back(Tup3u(last+j, last+j+1, last+num+j));
        }
    }
    last = (steps-1)*num;
    for(unsigned j = 0; j <= num-1; j++) {
        surface.VF.push_back(Tup3u(last+j+1, j+1, j));
        surface.VF.push_back(Tup3u(last+j, last+j+1, j));
    }
    return surface;
}

void drawSurface(const Surface &surface, bool shaded)
{
    // Save current state of OpenGL
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    if (shaded)
    {
        // This will use the current material color and light
        // positions.  Just set these in drawScene();
        glEnable(GL_LIGHTING);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        // This tells openGL to *not* draw backwards-facing triangles.
        // This is more efficient, and in addition it will help you
        // make sure that your triangles are drawn in the right order.
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
    }
    else
    {        
        glDisable(GL_LIGHTING);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        
        glColor4f(0.4f,0.4f,0.4f,1.f);
        glLineWidth(1);
    }

    glBegin(GL_TRIANGLES);
    for (unsigned i=0; i<surface.VF.size(); i++)
    {
        glNormal(surface.VN[surface.VF[i][0]]);
        glVertex(surface.VV[surface.VF[i][0]]);
        glNormal(surface.VN[surface.VF[i][1]]);
        glVertex(surface.VV[surface.VF[i][1]]);
        glNormal(surface.VN[surface.VF[i][2]]);
        glVertex(surface.VV[surface.VF[i][2]]);
    }
    glEnd();

    glPopAttrib();
}

void drawNormals(const Surface &surface, float len)
{
    // Save current state of OpenGL
    glPushAttrib(GL_ALL_ATTRIB_BITS);

    glDisable(GL_LIGHTING);
    glColor4f(0,1,1,1);
    glLineWidth(1);

    glBegin(GL_LINES);
    for (unsigned i=0; i<surface.VV.size(); i++)
    {
        glVertex(surface.VV[i]);
        glVertex(surface.VV[i] + surface.VN[i] * len);
    }
    glEnd();

    glPopAttrib();
}

void outputObjFile(ostream &out, const Surface &surface)
{
    
    for (unsigned i=0; i<surface.VV.size(); i++)
        out << "v  "
            << surface.VV[i][0] << " "
            << surface.VV[i][1] << " "
            << surface.VV[i][2] << endl;

    for (unsigned i=0; i<surface.VN.size(); i++)
        out << "vn "
            << surface.VN[i][0] << " "
            << surface.VN[i][1] << " "
            << surface.VN[i][2] << endl;

    out << "vt  0 0 0" << endl;
    
    for (unsigned i=0; i<surface.VF.size(); i++)
    {
        out << "f  ";
        for (unsigned j=0; j<3; j++)
        {
            unsigned a = surface.VF[i][j]+1;
            out << a << "/" << "1" << "/" << a << " ";
        }
        out << endl;
    }
}
