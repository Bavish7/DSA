#include<iostream>
using namespace std;

// DESIGN BROWSER HISTORY (LEETCODE 1472)
// USING 2 STACKS - TC=O(N), SC=O(N)

// Steps:
// 1. Constructor (`BrowserHistory`):
//    - Initialize the browser history with the homepage, pushing it onto the `browserStack`.
//
// 2. Visit (`visit`):
//    - Clear the forward stack (`fwdStack`) when a new URL is visited since you can't move forward after a new visit.
//    - Push the new URL onto the `browserStack` to simulate visiting a new page.
//
// 3. Back (`back`):
//    - Move back in the browser history by popping the top of the `browserStack` and pushing it onto the `fwdStack` (if there are more than one pages in the stack).
//    - Repeat this process `steps` times or until you can't move back anymore.
//    - Return the top of the `browserStack`, which represents the current page.
//
// 4. Forward (`forward`):
//    - Move forward in the browser history by popping the top of the `fwdStack` and pushing it onto the `browserStack`.
//    - Repeat this process `steps` times or until you can't move forward anymore.
//    - Return the top of the `browserStack`, which represents the current page.

stack<string> browserStack, fwdStack;
BrowserHistory(string homepage)
{
    browserStack.push(homepage);
}
void visit(string url)
{
    while (!fwdStack.empty())
    {
        fwdStack.pop();
    }
    browserStack.push(url);
}
string back(int steps)
{
    while (steps--)
    {
        if (browserStack.size() > 1)
        {
            string top = browserStack.top();
            browserStack.pop();
            fwdStack.push(top);
        }
        else
        {
            break;
        }
    }
    return browserStack.top();
}
string forward(int steps)
{
    while (steps--)
    {
        if (fwdStack.size() > 0)
        {
            string top = fwdStack.top();
            fwdStack.pop();
            browserStack.push(top);
        }
        else
        {
            break;
        }
    }
    return browserStack.top();
}