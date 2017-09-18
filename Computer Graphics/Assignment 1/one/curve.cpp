#include "curve.h"
#include "extra.h"
#ifdef WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
using namespace std;

namespace
{
    // Approximately equal to.  We don't want to use == because of
    // precision issues with floating point.
    inline bool approx( const Vector3f& lhs, const Vector3f& rhs )
    {
        const float eps = 1e-8f;
        return ( lhs - rhs ).absSquared() < eps;
    }

    
}

inline unsigned nChoosek(unsigned n, unsigned k) {
    if(k > n) return 0;
    if(k*2 > n) k = n-k;
    if(k == 0) return 1;
    unsigned res = n;
    for(unsigned i = 2; i <= k; i++) {
        res *= (n-i+1);
        res /= i;
    }
    return res;
}

inline unsigned Berstein(unsigned n, unsigned i, GLfloat t) {
    return nChoosek(n, i)*pow(t, i)*pow((1-t), n-i);
}

inline unsigned dBerstein(unsigned n, unsigned i, GLfloat t) {
    if(i == 0) return n*pow(1-t, n-1);
    if(i == n) return n*pow(t, n-1);
    return nChoosek(n, i)*pow(t, i-1)*pow(1-t, n-i-1)*(i*(1-t)+(n-i)*t);
}

Curve evalBezier( const vector< Vector3f >& P, unsigned steps )
{
    // Check
    if( P.size() < 4 || P.size() % 3 != 1 )
    {
        cerr << "evalBezier must be called with 3n+1 control points." << endl;
        exit( 0 );
    }

    // TODO:
    // You should implement this function so that it returns a Curve
    // (e.g., a vector< CurvePoint >).  The variable "steps" tells you
    // the number of points to generate on each piece of the spline.
    // At least, that's how the sample solution is implemented and how
    // the SWP files are written.  But you are free to interpret this
    // variable however you want, so long as you can control the
    // "resolution" of the discretized spline curve with it.

    // Make sure that this function computes all the appropriate
    // Vector3fs for each CurvePoint: V,T,N,B.
    // [NBT] should be unit and orthogonal.

    // Also note that you may assume that all Bezier curves that you
    // receive have G1 continuity.  Otherwise, the TNB will not be
    // be defined at points where this does not hold.

    // cerr << "\t>>> evalBezier has been called with the following input:" << endl;

    // cerr << "\t>>> Control points (type vector< Vector3f >): "<< endl;
    // for( unsigned i = 0; i < P.size(); ++i )
    // {
    //     cerr << "\t>>> " << P[i] << endl;
    // }

    // cerr << "\t>>> Steps (type steps): " << steps << endl;
    // cerr << "\t>>> Returning empty curve." << endl;

    unsigned n = P.size()-1;
    vector<GLfloat> timePoints(steps);
    for(unsigned i = 0; i < steps; i++) timePoints[i] = i*1/(steps-1);
    Curve Bezier(steps);
    for(unsigned i = 0; i < steps; i++) {
        Bezier[i].V = Vector3f(0.0);
        Bezier[i].T = Vector3f(0.0);
        Bezier[i].N = Vector3f(0.0);
        Bezier[i].B = Vector3f(0.0);
        // V
        for(unsigned j = 0; j <= n; j++) {
            Bezier[i].V += P[j]*Berstein(n, j, timePoints[i]);
        }
        // T
        for(unsigned j = 0; j <= n; j++) {
            Bezier[i].T += P[j]*dBerstein(n, j, timePoints[i]);
        }
        // normalizing
        Bezier[i].T = Bezier[i].T.normalized();
        // N
        for()
    }
    return Bezier;

    // Right now this will just return this empty curve.
    // return Curve();
}

Curve evalBspline( const vector< Vector3f >& P, unsigned steps )
{
    // Check
    if( P.size() < 4 )
    {
        cerr << "evalBspline must be called with 4 or more control points." << endl;
        exit( 0 );
    }

    // TODO:
    // It is suggested that you implement this function by changing
    // basis from B-spline to Bezier.  That way, you can just call
    // your evalBezier function.

    cerr << "\t>>> evalBSpline has been called with the following input:" << endl;

    cerr << "\t>>> Control points (type vector< Vector3f >): "<< endl;
    for( unsigned i = 0; i < P.size(); ++i )
    {
        cerr << "\t>>> " << P[i] << endl;
    }

    cerr << "\t>>> Steps (type steps): " << steps << endl;
    cerr << "\t>>> Returning empty curve." << endl;

    // Return an empty curve right now.
    return Curve();
}

Curve evalCircle( float radius, unsigned steps )
{
    // This is a sample function on how to properly initialize a Curve
    // (which is a vector< CurvePoint >).
    
    // Preallocate a curve with steps+1 CurvePoints
    Curve R( steps+1 );

    // Fill it in counterclockwise
    for( unsigned i = 0; i <= steps; ++i )
    {
        // step from 0 to 2pi
        float t = 2.0f * M_PI * float( i ) / steps;

        // Initialize position
        // We're pivoting counterclockwise around the y-axis
        R[i].V = radius * Vector3f( cos(t), sin(t), 0 );
        
        // Tangent vector is first derivative
        R[i].T = Vector3f( -sin(t), cos(t), 0 );
        
        // Normal vector is second derivative
        R[i].N = Vector3f( -cos(t), -sin(t), 0 );

        // Finally, binormal is facing up.
        R[i].B = Vector3f( 0, 0, 1 );
    }

    return R;
}

void drawCurve( const Curve& curve, float framesize )
{
    // Save current state of OpenGL
    glPushAttrib( GL_ALL_ATTRIB_BITS );

    // Setup for line drawing
    glDisable( GL_LIGHTING ); 
    glColor4f( 1, 1, 1, 1 );
    glLineWidth( 1 );
    
    // Draw curve
    glBegin( GL_LINE_STRIP );
    for( unsigned i = 0; i < curve.size(); ++i )
    {
        glVertex( curve[ i ].V );
    }
    glEnd();

    glLineWidth( 1 );

    // Draw coordinate frames if framesize nonzero
    if( framesize != 0.0f )
    {
        Matrix4f M;

        for( unsigned i = 0; i < curve.size(); ++i )
        {
            M.setCol( 0, Vector4f( curve[i].N, 0 ) );
            M.setCol( 1, Vector4f( curve[i].B, 0 ) );
            M.setCol( 2, Vector4f( curve[i].T, 0 ) );
            M.setCol( 3, Vector4f( curve[i].V, 1 ) );

            glPushMatrix();
            glMultMatrixf( M );
            glScaled( framesize, framesize, framesize );
            glBegin( GL_LINES );
            glColor3f( 1, 0, 0 ); glVertex3d( 0, 0, 0 ); glVertex3d( 1, 0, 0 );
            glColor3f( 0, 1, 0 ); glVertex3d( 0, 0, 0 ); glVertex3d( 0, 1, 0 );
            glColor3f( 0, 0, 1 ); glVertex3d( 0, 0, 0 ); glVertex3d( 0, 0, 1 );
            glEnd();
            glPopMatrix();
        }
    }
    
    // Pop state
    glPopAttrib();
}
