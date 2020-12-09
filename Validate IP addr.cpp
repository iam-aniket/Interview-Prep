class Solution {
public:
    bool isValidIpV4(string& ip)
    {
        if (count(ip.begin(), ip.end(), '.') != 3) {return false;}
        istringstream ss(ip);
        string num;
        int count = 0;
        while(getline(ss, num, '.')) {
            count ++; 
            int len = num.size();
            if (len == 0 || len > 3) {return false;}
            if(len > 1 && num[0] == '0') {return false;}
            int val = 0;
            for (char c : num) {
                if(!isdigit(c)) {return false;}
                val = val * 10 + (c-'0');
                if(val > 255) {return false;}
            }            
        }
        if(count != 4) {return false;}
        return true;
    }
    
    bool isValidIpV6(string& ip) 
    {
        if (count(ip.begin(), ip.end(), ':') != 7) {return false;}
        istringstream ss(ip);
        string num;
        string validChar = "0123456789abcdefABCDEF";
        int count = 0;
        while(getline(ss, num, ':')) {
            count ++; 
            int len = num.size();
            if (len == 0 || len > 4) {return false;}
            for (char c : num) {
                if (!isalnum(c) || validChar.find(c) == string::npos) { return false; }
            }            
        }
        if(count != 8) {return false;}
        return true;        
    }
    
    string validIPAddress(string IP) 
    {
        if (isValidIpV4(IP)) { return "IPv4"; }
        if (isValidIpV6(IP)) { return "IPv6"; }
        return "Neither";
    }    
};
