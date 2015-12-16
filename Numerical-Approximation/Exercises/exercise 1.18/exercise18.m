function [fvalue] = exercise18(n, k)
    str = num2str(n);
    flag = get_pos_num(str);
   if n >= 1000000000
       value1 = more_than_billion(str, flag, k);
       value2 = str(length(str) -3: length(str));
        value = strcat(value1, value2);
    elseif n > 1
        value = more_than_zero(str, flag, k);
    elseif n > 0.001
        value = less_than_zero(str, flag, k);
%     if n >= 1
%         num = str2num(str);
%         value = more_than_one(num, k);
    else
        value1 = more_than_zero(str, flag, k);
        value2 = str(length(str)-3 : length(str));
        value = strcat(value1, value2);
    end;
    fvalue = sprintf('%g', str2num(value));

    function [value] = more_than_billion(str, flag, k)
        last = flag + k +1;
        string = rounding(str, last, k);
        value = string(1:last - 1);
        

function [pos] = get_pos_pnt(str)
        pos = length(str);
        for i = 1: length(str)
            if str(i) == '.'
                pos = i;
                break;
            end;
        end;
  
        
        
function [value] = more_than_zero(str, flag, k)
    count = length(str);
    last = flag + k + 1;
    count = get_pos_pnt(str);
    if count ~= 2
        last = last - 1;
    end;
    string = rounding(str, last, k);
    if last < count
        string(last : count - 1) = '0';
        value = string(1 : count);
    else
        value = string(1 : last -1);
    end;
    
 function [value] = less_than_zero(str, flag, k)
     last = flag + k;
     string = rounding(str, last, k);
     value = string(1 : last - 1);
     
    
 function [flag] = get_pos_num(str)
    for i = 1 : length(str)
        if str(i) ~= '0' && str(i) ~= '.'
            flag = i;
            break;
        end;
    end;

    
function [string] = rounding(str, last, k)
    count = get_pos_pnt(str);
    if count - 1 == k || length(str) - 1 == k || last >= length(str)
        string = str;
    else
    tail = str2num(str(last));
    if tail > 5
        if str(last - 1) == '.'
            last = last - 1;
        end;
        if str(last - 1) == '9'
            str(last - 1) = num2str(0);
            last = last - 1;
            while str(last) == '0'
                str(last - 1) = num2str(mod( (str2num(str(last - 1)) +1), 10));
                last = last - 1;
            end;
        else
            str(last - 1) = num2str(str2num(str(last - 1)) + 1);
        end;
        string = str;
    elseif tail < 5
        string = str;
    else 
        if str(last) == '.'
            last = last - 1;
        end;
        if mod(str(last - 1), 2) == 0 && is_zero(str, last) == 0
            string = str;
        else
            str(last - 1) = num2str(str2num(str(last - 1)) + 1);
            string = str;
        end;
    end;
    end;
    
    function [value] =  more_than_one(str, k)
        value = sprintf('%0.*g', k, str);
        
        
        function [value] = is_zero(str, last)
            value = -1;
            for i = last+1 : length(str)
                if str(i) ~= 0
                   value = 1;
                end;
            end;
            
            
            