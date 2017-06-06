function [value] = new_value(n, k)
    str = num2str(n);
    pos_num = get_pos_num(str);
    pnt_pos = get_pos_pnt(str);
    if pos_num == 1 && k < pnt_pos
        value = more_than_zero(str, flag, k);
    else
        value = str2num( sprintf('%-1.*f', k + pos_num - pnt_pos, n));
    end;


function [flag] = get_pos_num(str)
    for i = 1 : length(str)
        if str(i) ~= '0' && str(i) ~= '.'
            flag = i;
            break;
        end;
    end;
    
    
function [pos] = get_pos_pnt(str)
        for i = 1: length(str)
            if str(i) == '.'
                pos = i;
                break;
            end;
        end;
        pos = length(str) + 1;
        
function [value] = more_than_zero(str, flag, k)
    count = length(str);
    last = flag + k + 1;
    if last > length(str)
        last = last - 1;
    end;
    for i = 1 : length(str)
        if str(i) == '.'
            count = i;
            break;
        end;
    end;
    if count ~= 2
        last = last - 1;
    end;
    string = rounding(str, last);
    if last < count
        string(last : count) = '0';
        value = string(1 : count);
    else
        value = string(1 : last - 1);
    end;
    
    function [string] = rounding(str, last)
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
        if str(last - 1) == '.'
            last = last - 1;
        end;
        if mod(str(last - 1), 2) == 0
            string = str;
        else
            str(last - 1) = num2str(str2num(str(last - 1)) + 1);
            string = str;
        end;
    end;
