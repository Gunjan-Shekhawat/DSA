/*
PROBLEM : Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.

          Chech whether A has redundant braces or not.

          Return 1 if A has redundant braces, else return 0.

          Note: A will be always a valid expression.
          
          FOR EXAMPLE --
          
          
                    Input 1:
              A = "((a + b))"
          Output 1:
              1
              Explanation 1:
                  ((a + b)) has redundant braces so answer will be 1.

          Input 2:
              A = "(a + (a + b))"
          Output 2:
              0
              Explanation 2:
                  (a + (a + b)) doesn't have have any redundant braces so answer will be 0.
                  
          https://www.interviewbit.com/problems/redundant-braces/
*/

int Solution::braces(string A) {
stack <int> s;
for(int i = 0; i < A.size(); i++) {
if(A[i] == '+' || A[i] == '/'|| A[i] == '*' || A[i] == '-' || A[i] == '(' ){
s.push(A[i]);
}
else if(A[i] == ')') {
int flag = 0;
while(s.top() != '(') {
s.pop();
flag++;
}
s.pop();
if(flag == 0) {
return 1;
}
}
}
return 0;
}

