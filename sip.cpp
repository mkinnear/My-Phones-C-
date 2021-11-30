#include <iostream>
#include <string>

#define line std::cout << "------------------------------------------------------" << std::endl
#define log(x) std::cout << x

const std::string sipMsg[] = {"",
"INVITE sip:01794840191@192.168.0.111:53849;line=c2y4zot7 SIP/2.0\r\n",
"Via: SIP/2.0/UDP 192.168.1.10:4144;branch=z9hG4bcxsaa.5d2a1c66.0\n", //4th
"Via: SIP/2.0/UDP 192.168.1.11:4144;branch=z9hG4bKf49a.4a5d5c8e.0\r\n", //3rd
"VIA: SIP/2.0/UDP 172.16.1.24:4144;branch=z9hhgfdhgdff49a.deadbeef.0\n", //2nd
"Via: SIP/2.0/UDP 10.100.10.58:4144;branch=h5623jG4bKf49a.c0ffee000.0\r\n", //1st
"t: <sip:01794840191@192.168.1.10>\n",
"f: CTI Services<sip:01794840191@192.168.1.10>;tag=c10dcfe5\n",
"i: 3fcf75c1452ca45ad4f01a93df001510@192.168.1.10\n",
"CSeq: 1 INVITE\n",
"User-Agent: Asterisks\n",
"Max-Forwards: 10\n",
"m: <sip:01794840191@192.168.1.10:4144;did=719.6d51e9e1>\n",
"Alert-Info: <http://127.0.0.1>;info=alert-autoanswer;delay=1\n",
"c: application/sdp\n",
"l: 152\n",
"Route: <sip:01794840191@192.168.1.10:4144>\n",
"\n\n"};

void    displaySipMsg(void)
{
    int     len = (std::end(sipMsg) - std::begin(sipMsg));
    while (len--)
    {
        if ((sipMsg[len]).find("SIP/2.0/UDP") != std::string::npos)
            log(sipMsg[len]);
    }
}

int main (void)
{
    line;
    log("\t\tProgram Start\n");
    line;
    displaySipMsg();
    line;
}

/** STEPS **
-------------
You may edit/resize the array, it will find the elements with the SIP/2.0/UDP data you want to display:
-------------
 * [1]: I created a function displaySipMsg() to cater for elements holding SIP/2.0/UDP, There is 1 other uwanted elements that also holds SIP/2.0 
 * [2]: copy the length of the array incase it needs to be referenced again
 * [3]: Strings end with a null terminating character, so decrementing from the end of the array till it reaches 0 (false) seems plausible
 * [3]: Next find the common string SIP/2.0/UDP in to reference the data I want to extract/display from the elements in the array
 * [4]: Each element in the array hold a \n character, so std::endl isn't necessary
 * [5]: pass the function to main(), main() can call the function as many times as it wants while still keeping the main() clean
 */