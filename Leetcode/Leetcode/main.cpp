//
//  main.cpp
//  Leetcode
//
//  Created by Jinhao Ping on 11/10/15.
//  Copyright © 2015 Jinhao Ping. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <set>
#include <cstdlib>
#include <cmath>
#include <sstream>

using namespace std;

bool canWinNim(int n)
{
    if(n % 4 == 0) return false;
    return true;
    
}

int addDigits(int num) {
    
    if (num < 10 ) return num;
    
    int result = 0;
    while( num  > 10 ){
       
        result = num%10 + result;
        
        num = num/10;
    
    }
    result = result + num;
    
    while(result > 10){
        return  addDigits(result);
    }
    return result;
}


struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    
    node -> val = node -> next -> val;
    node -> next = node -> next -> next;
    
    
}

void moveZeroes(vector<int>& nums){
    
    
    for(int i = 0; i < nums.size() - 1; i++ ){
        if(nums[i] == 0){
            for (int j = i + 1; j < nums.size(); j ++ ){
                if(nums[j] != 0){
                    
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                    break;
                }
            }
        }
    }
    
    
    
}


struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* invertTree(TreeNode* root) {
    
    if(root -> left == NULL){
        return root;
    }
    
    if(root -> left != NULL){
        int tmp =  root -> left -> val;
        root -> left -> val = root -> right -> val;
        root -> right -> val = tmp;
        
        
    }
    
    
    if(root -> left -> left != NULL){
        TreeNode *t1 = root -> left -> left;
        TreeNode *t2 = root -> left -> right;
        
        root -> left -> left = root -> right -> left;
        root -> left -> right = root -> right -> right;
        root -> right -> left = t1;
        root -> right -> right = t2;

    }
    
    invertTree(root -> left);
    invertTree(root -> right);
    
    return root;
    
}



int solution(int N) {
    
    int largest = 0;
    int shift = 0;
    int temp = N;
    int i;
    for (i = 1; i < 30; ++i) {
        
        int index = (temp & 1);
        temp = ((temp >> 1) | (index << 29));
        if (temp > largest) {
            largest = temp;
            shift = i;
        }
        
    }
    return shift;
}


int solution2(int N) {
    int largest = 0;
    int shift = 0;
    int temp = N;
    cout << temp << endl;
    cout << (temp & 1) << endl;
    
    cout << (temp >> 1 ) << endl;
    cout << (temp << 29) << endl;
    cout << "2222"<<endl;
    for (int i = 1; i < 30; ++i) {
        
        int index;
        
        index = (temp & 1);
        
        
        temp = ((temp >> 1) | (index << 29));
        if (temp > largest) {
            largest = temp;
            shift = i;
        }
    }
    return shift;

   


}

int solution3(int N) {
    long  m = N;
    long  max = 0;
    int shift = 0;
    for (int i = 1; i < 30; i ++) {
        
        m  = ((N  << i) & 0x3fffffff  )| (N >> (30-i));
        if ( m > max) {
            max = m;
            shift = i;
        }
    }
    return shift;
}

int solution4(int N) {
    
    int largest = 0;
    int shift = 0;
    int temp = N;
    
    int i;
    for (i = 1; i < 30; ++i) {
        
        int index = (temp & 1);
        temp = ((temp >> 1) | (index << 29));
        if (temp > largest) {
            largest = temp;
            shift = i;
        }
        
    }
    return shift;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q ==  NULL) return true;
    else if( p == NULL && q != NULL) return false;
    else if(p != NULL && q== NULL ) return false;
    else if(p -> val != q-> val)return false;
    else{
        return  (isSameTree(p->left, q->left ) && isSameTree(p->right, q->right
                                                           ));
        
    }
    
}

bool isAnagram(string s, string t) {
    
    if(s.size()!= t.size()) return false;
    
    
    vector <char> a;
    vector <char> b;
    
    for(int i = 0; i < s.size(); i++){
        a.push_back(s.at(i));
    }
    
    
    for(int i = 0; i<t.size();i++){
        b.push_back(t.at(i));
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(),b.end());
    
    for(int i = 0; i < s.size(); i++){
        if(a[i] != b[i]){
            return false;
        }
    }
  
    
    return true;
    
}

int titleToNumber(string s) {
    int result = 0;
    
    for(int i = 0; i < s.size(); i++){
        result = result * 26 + s.at(i) - 'A' + 1;
    }
    return result;
}


int majorityElement(vector<int>& nums) {
    
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    
    
    int result =  nums[n/2];
    
    return result;
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    if(!root) return root;
    
    if((root-> val - p->val) * (root->val -q->val)<= 0) return root;
    
    if(p-> val > root -> val && q-> val > root -> val){
        return lowestCommonAncestor(root->right, p, q);
    }
    
    else
        return lowestCommonAncestor(root->left, p, q);
    
    
}

ListNode* oddEvenList(ListNode* head) {
    
    if(!head ||head->next == nullptr ) return head;
    
    ListNode * odd = head;
    ListNode * even_head = head -> next;
    ListNode * even = head -> next;
    
    while(even != nullptr && even->next != nullptr){
        
        odd -> next = even -> next;
        even -> next = odd -> next -> next;
        even = even -> next;
        odd = odd -> next;
    }
    odd -> next = even_head;
    return head;
}






int romanToInt(string s) {
    
    unordered_map <char, int> mymap =  { {'I', 1},
                                    {'V', 5},
                            {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
    
    auto x =mymap.find(s.back());
    int result =x -> second;
    
    for(int i = int(s.length() - 2); i>=0; i-- ){
        
        if(mymap.find(s.at(i))->second >= mymap.find(s.at(i+1))->second){
            result =mymap.find(s.at(i))->second + result;
        }
        else{
            result = result - mymap.find(s.at(i))->second;
        }
    }

    return result;
}

int hammingWeight(uint32_t n) {
    
    int count = 0;
    
    while(n){
        
        n = (n & (n-1));
        
        count ++ ;
    }
    return count;
    
}



int climbStairs(int n) {
    if(n==0||n==1||n==2) return n;
    
    int mem[n];
    mem[0] = 1;
    mem[1] = 2;
    
    for(int i = 2; i < n; i++ ){
        
        mem[i] = mem[i-1] + mem[i-2];
    }
    return mem[n-1];
}



ListNode* deleteDuplicates(ListNode* head) {
    
    if(head == nullptr|| head -> next == nullptr){
        return  head;
    }
    ListNode *current = head -> next;
    ListNode *pre = head;
    
    while(current != nullptr){
        
        if(pre->val == current->val){
            pre->next = current->next;
            current = current -> next;
        }
        else{
            pre = current;
            current = current -> next;
        }
        
    }

    
    
    return head;
}


class Queue {
public:
    // Push element x to the back of queue.
    
    stack <int> input;
    stack <int> output;
    
    
    void push(int x) {
        input.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        output.pop();
    
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }
    
    // Get the front element.
    int peek(void) {
        
        
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        int tmp = output.top();
        
        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
        
        return tmp;
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        
        return input.empty();
    }
};

int height(TreeNode *root)
{
    if (root == nullptr) return 0;
    return max(height(root -> left), height(root -> right)) + 1;
}


bool isBalanced(TreeNode* root) {
    if(root == nullptr) return true ;
    
    return isBalanced(root -> left) && isBalanced(root -> right) && abs(height(root -> left ) - height(root -> right)) <= 1;
    
    
}


bool isSymmetric(TreeNode* root) {
    
    if(root == nullptr) return true;
    
    queue <TreeNode*> q1;
    queue <TreeNode*> q2;
    
    q1.push(root -> left);
    q2.push(root -> right);
    
    while(q1.empty() == 0 && q2.empty() == 0  ){
        TreeNode * left = q1.front();
        TreeNode * right = q2.front();
        q1.pop();
        q2.pop();
        
        if(left == nullptr && right == nullptr){
            continue;
        }
        if(left == nullptr || right ==nullptr ){
            return false;
        }
        if(left->val != right -> val){
            return false;
        }
        q1.push(left->left);
        q1.push(left->right);
        q2.push(right->right);
        q2.push(right->left);
        
    }
    return true;
    
    
   
}




void read(TreeNode *root,stack<int> &s ){
    if(root -> right != nullptr){
        s.push(root->right->val);
    }
    if(root -> left!= nullptr){
        s.push(root->left->val);
    }else{
        return;
    }
    
    read(root -> right, s);
    read(root -> left,s);
    
}


int removeDuplicates(vector<int>& nums) {
   
    if(nums.size() ==0 ) return 0 ;
    if(nums.size() ==1  ) return 1 ;

    int i = 1;
    while (i < nums.size()) {
        if(nums[i] == nums[i-1]){
            nums.erase(nums.begin() + i);
        }else{
            i++;
 
        }
    }
    return nums.size();
}



vector<vector<int>> generate(int numRows) {
    
    vector<vector<int>> result;
    
    for(int i = 0 ; i < numRows; i++ ){
        
        result.push_back(vector<int> (i+1, 1));
        for(int j = 1; j < i; j++){
            result[i][j] = result[i-1][j-1] + result[i-1][j];
         }
        
    }
    return result;
}


bool hasPathSum(TreeNode* root, int sum) {
    
    if(root  == nullptr) return false;
    
    if(root -> val == sum && root->right == nullptr && root->left == nullptr){
        return true;
    }
    
    return hasPathSum(root -> left , sum - root-> val) || hasPathSum(root -> right, sum - root -> val);
    
    
    
}


bool isPalindrome(int x) {
    string reverse = "";
    
    
    int t = abs(x) ;
    while(x){
        string tmp = to_string(x%10);
        reverse = reverse.append(tmp);
        x = x/10;
    }
    
    int y = atoi(reverse.c_str());
    cout << y << endl;
    cout << "xxxx " << x << endl;
     if(t == y){
        cout << "1111" << endl;
        return true;
    }
    else return false;
}

class Stack {
public:
    
    queue <int> q1;
    queue <int> q2;
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }
    
    // Removes the element on top of the stack.
    void pop() {
        int size  = q1.size();
        while(size != 1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    // Get the top element.
    int top() {
        int size  = q1.size();
        while(size != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
       
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        
        return x;

    }
    
    // Return whether the stack is empty.
    bool empty() {
        if(q1.empty()){
            return true;
        }
        else return false;
    }
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  
    ListNode * p1 = headA;
    ListNode * p2 = headB;
    
    while(p1 != nullptr && p2 != nullptr  && p1-> val != p2 -> val){
        p1 = headA -> next;
        p2 = headB -> next;
        
        if(p1 ==  p2) return p1;
        
        if(p1 == nullptr){
            p1 = headB;
        }
        if(p2 == nullptr){
            p2 = headA;
        }

    }
    return nullptr;
}




void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
    if(m == 0) {
        nums1 = nums2;
        return;
    }
    if(n == 0){
        return;
    }
    vector<int> tmp;
    for(int i = 0; i<m ; i++){
        
        tmp.push_back(nums1[i]);
        
    }
    for(int i = 0; i<n; i++){
        
        tmp.push_back(nums2[i]);
        
    }

    nums1 = tmp;
    sort(nums1.begin(), nums1.end());
    
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    
    unordered_map<int, int> m;
    int position = 0 ;
    
    for(int i = 0; i < nums.size(); i++){
        
        if(m.find(nums[i]) != m.end()){
            if(i - m[nums[i]] <=k ){
                return true;
            }

        }
        
        m[nums[i]] = i;
    }
    
    return false;
    
    
    
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(n == 1){
        head = head -> next;
        return head;
    }
    
    ListNode * p = head;
    int size = 0;
    while(p!=nullptr){
        p = p->next;
        size ++;
    }
    
    
    int position = size - n;
    
    ListNode * t = head;
    
    for(int i = 0; i < position; i++){
        t = t-> next;
    }
    t -> next = t -> next ->next;
    return head;
}



bool isValid(string s) {
    
    stack<char> tmp;
    if(s == "") return true;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '{' ||s[i] == '['){
            tmp.push(s[i]);
        }
        else if(s[i] == ')'){
            if(tmp.empty() || tmp.top() != '('){
                return false;
            
            }else if(tmp.top() == '('){
                tmp.pop();
            }
        }
        else if(s[i] == '}'){
            if(tmp.empty() || tmp.top() != '{'){
                return false;
            }else if(tmp.top() == '{'){
                tmp.pop();
            }
        }
        else if(s[i] == ']'){
            if(tmp.empty() || tmp.top() != '['){
                return false;
            }else if(tmp.top() == '['){
                tmp.pop();
            }
        }
    }
    return tmp.empty();
    
    
}




bool isIsomorphic(string s, string t) {
    if(s.length() != t.length()){
        return false;
    }
    
    unordered_map<char, char> m;
    
    unordered_set <char> unique;
    for (int i = 0; i < s.length(); i++){
       
        
        if(m.find(s[i]) == m.end()){
            m[s[i]] = t[i];
            
            if(unique.find(t[i]) == unique.end()){
                unique.insert(t[i]);
            }else {
                return false;
            }

            
        }
    }
    
    char tmp[t.length()];
    for(int i = 0; i < t.length(); i++ ){
        tmp[i] = m[s[i]];
    }
    
    string str
    (tmp, t.length());
    if(str == t) return true;
    else return false;
}


string getHint(string secret, string guess) {
    
    int arrayA[10] = {0,0,0,0,0,0,0,0,0,0};
    int arrayB[10] = {0,0,0,0,0,0,0,0,0,0};
    
    
    int A = 0;
    int B = 0;
    
    
    string left = "";
    for(int i = 0; i < secret.length(); i++){
        if(secret[i] == guess[i]){
            A++ ;
        }else{
            
            int j = secret[i] - '0' ;
            arrayA[j]++;
            int k = guess[i] - '0';
            arrayB[k]++;
            
        }
    }
    
    for(int i = 0; i < 10; i++){
        
        if(arrayA[i] != 0 && arrayB[i] != 0){
            
            if(arrayA[i] < arrayB[i]){
                
                B = B + arrayA[i];
                
            }
            else{
                
                B = B + arrayB[i];
            }
            
        }
        
    }
    


    string str = to_string(A) + "A" +to_string(B) + "B";
    return str;
}



ListNode* removeElements(ListNode* head, int val) {
    while(head != nullptr && head -> val == val){
        head = head -> next;
    }
    queue<int> q;
    ListNode *cur = head;
    ListNode *tmp = head;
    int count = 0;
    while(cur !=  nullptr){
        if(cur -> val == val){
            q.push(count-1);
        }
        count ++;
        cur = cur -> next;
    }
    
    int i = 0;
    while(tmp != nullptr && q.empty() != true){
        if(i == q.front()){
            if(tmp->next -> next != nullptr) tmp -> next = tmp -> next -> next;
            else{
                tmp -> next = nullptr;
            }
            
            while(tmp -> next != nullptr && tmp -> next -> val == val){
                tmp -> next = tmp -> next -> next;
                q.pop();
                i++;
            }
            q.pop();
            i++;
        }
        i++;
        tmp = tmp -> next;
        
    }
    
    return head;
}

int myAtoi(string str) {
    
    if(str == "+" || str == "-"){
        return 0;
    }
    int p = 0;
    int n = 0;
    int space = 0;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '+' ){
            p++;
            if(str[i+1] == '+' ||str[i+1] == '-' || str[i+1] == ' ') return 0;
        }
        else if(str[i] == '-'){
            n++;
            if(str[i+1] == '+' ||str[i+1] == '-' || str[i+1] == ' ') return 0;
            
        }
        else if(str[i] == ' '){
            space ++;
        }
        
        if(str[i]=='0' ||str[i]=='1' ||str[i]=='2' ||str[i]=='3' ||str[i]=='4' ||str[i]=='5' ||str[i]=='6' ||str[i]=='7' ||str[i]=='8' ||str[i]=='9' ){
            break;
        }
    }
    if(n > 1 || p > 1 ) return 0 ;
    if(n == 1 && p > 0 ) return 0;
    if (p == 1 && n > 0 ) return 0;
    
    string tmp = "";
    for(int i = 0; i < str.length() ; i++){
        
        if(i>= n + p + space ){
            if(str[i]=='0' ||str[i]=='1' ||str[i]=='2' ||str[i]=='3' ||str[i]=='4' ||str[i]=='5' ||str[i]=='6' ||str[i]=='7' ||str[i]=='8' ||str[i]=='9' ){
                tmp = tmp + str[i];
                
            }
            else{
                break;
            }
        }
    }
    if(tmp == "") return 0;
    int result = 0;
    for(int i = 0; i < tmp.length(); i++){
        int s = tmp[i]-'0';
        if(result +  s*pow(10,int(tmp.length()-int(i)-1))>= INT_MAX){
            
            if(n%2 && result +  s*pow(10,int(tmp.length()-int(i)-1)) == INT_MAX ){ return INT_MIN + 1 ;}
            else if (n%2 && result +  s*pow(10,int(tmp.length()-int(i)-1)) > INT_MAX){
                return INT_MIN;
            }
            
            return INT_MAX;}
        else if(result +  s*pow(10,int(tmp.length()-int(i)-1))<= INT_MIN) {   return INT_MIN;}
        else result = result +  s*pow(10,int(tmp.length()-int(i)-1));
        
    }
    
    if(n % 2) result = -result;
    
    else result = result;
    
    return result;
}


int compareVersion(string version1, string version2) {
    
    int a = atoi(version1.c_str());
    int b = atoi(version2.c_str());
    
    if(a > b ){
        return 1;
    }else if (a < b ){
        return -1;
    }
    else{
        string tmp1 = "";
        string tmp2 = "";
        int index1 = 0;
        int index2 = 0;
        bool exist1 = false;
        bool exist2 = false;
        int t1 = 0;
        int t2 = 0;
        for(int i = 0; i < version1.length(); i++){
            if(version1[i] == '.'){
                index1 = i;
                exist1 = true;
                break;
            }
        }
        if(exist1){
            for(int i = index1 + 1; i < version1.length(); i++){
                tmp1.push_back(version1[i]);
            }
            t1 = atoi(tmp1.c_str());
        }
        else{
            t1 = a;
        }
        
        for(int i = 0; i < version2.length(); i++){
            if(version2[i] == '.'){
                index2 = i;
                exist2 = true;
                break;
            }
        }
        if(exist2){
            for(int i = index2 + 1; i < version2.length(); i++){
                tmp2.push_back(version2[i]);
            }
            t2= atoi(tmp2.c_str());
        }
        else{
            t2 = a;
        }
        
        if(exist1 == false && exist2 == true) return -1;
        if(exist1 == true && exist2 == false ) return 1;

        if(t1 > t2) return 1;
        if(t1 < t2 ) return -1;
        return 0;
    }
}



void rotate(vector<int>& nums, int k) {
    if(k > nums.size()){
        
        k = k%nums.size();
    }
    vector<int> tmp;
    int t = k;
    for (int i = nums.size()-k ; k != 0; k--){
        tmp.push_back(nums[i]);
        i++;
    }
    
    for(int i = 0; i < tmp.size(); i++){
        cout << tmp[i] <<  " ";
    }
    cout << endl;
    cout <<nums.size() << " 111 " << endl;
    cout << k << " k" << endl;
    for(int i = 0; i < nums.size() - t; i++ ){
        tmp.push_back(nums[i]);
    }
    
    for(int i = 0; i < tmp.size(); i++){
        cout << tmp[i] <<  " ";
    }
    
    
    for(int i = 0; i <nums.size(); i ++  ){
        nums[i] = tmp[i];
    }
    return;
}

vector<int> twoSum(vector<int>& nums, int target) {
   
    unordered_map<int, int> map;
    vector<int> result;
    
    for(int i =0 ; i < nums.size(); i++){
        int tmp = target - nums[i];
        if(map.find(tmp)==map.end()){
            map[nums[i]] = i;
        }else{
            result.push_back(i);
            result.push_back(map[tmp]);
            return result;
        }
    }
    return result;
}


bool isPalindrome(string s) {
    if(s=="") return true;
    string tmp1 = "";
    for(int i = 0; i<s.length(); i++){
        if(isalnum(s[i])){
            tmp1.push_back(tolower(s[i]));
        }
    }
    string tmp2 = "";
    for(int i = s.length() -1 ; i >= 0; i-- ){
        if(isalnum(s[i])){
            tmp2.push_back(tolower(s[i]));
        }
    }
    
    if(tmp1 == tmp2) return true;
    else return false;
}

bool isPalindrome(ListNode* head) {
    stack<int> s;
    ListNode * cur = head;
    while(cur != nullptr){
        s.push(cur->val);
        cur = cur -> next;
    }
    bool flag = true;
    while(head!=nullptr){
        if(head->val== s.top()){
            s.pop();
            head = head -> next;
        }else{
            flag = false;
            break;
        }
    }
    return flag;
}

vector<int> countBits(int num) {
    
    vector<int> result;
    for(int i= 0; i<= num ; i++){
        result.push_back(__builtin_popcount(i));
    }
    return result;
}
/*
vector<int> singleNumber(vector<int>& nums) {
    unordered_map<int, int> m;
    for(int i = 0; i < nums.size(); i++){
        if(m.find(nums[i]) == m.end()){
            m[nums[i]] = 1;
        }else{
            m[nums[i]]++;
        }
    }
    vector<int> result;
    int i = 0;
    for( i = 0; i < nums.size(); i++ ){
        if(m[nums[i]] == 1){
            result.push_back(nums[i]);
        }
    }
    return result;
}

*/
vector<int> productExceptSelf(vector<int>& nums) {
    
    vector<int> first;
    first.push_back(nums[0]);
    for(int i = 1; i < nums.size(); i++){
        first[i] = first[i-1] * nums[i];
        first.push_back(first[i]);
    }
    
    vector<int> second(nums.size(),1);
    second[nums.size() -1] = nums[nums.size() - 1];
    
    for(int i = nums.size() - 1 - 1; i >= 0; i --){
        second[i] = second[i+1] * nums[i];
    }
    
    vector<int> result(nums.size(), 1);
    result[0] = second[1];
    result[nums.size() - 1] = first[nums.size() -2];
    for(int i= 1; i < nums.size()-1; i++){
        
        
        result[i] = first[i-1] * second[i+1];
    }

    
    return result;
    
}

void preorder(TreeNode *root, vector<int> &result){
    
    if(root == nullptr){
        return;
    }else{
        result.push_back(root->val);
        preorder(root->left,result);
        preorder(root->right,result);
    }
}

vector<int> preorderTraversal(TreeNode* root) {
    
    vector<int> result;
    preorder(root, result);
    
    return result;
}



void inorder(TreeNode *root, vector<int> &result){
    if(root == nullptr){
        return;
    }else{
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);


    }
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorder(root, result);
    return result;
}
int missingNumber(vector<int>& nums) {
    
    int a = 0;
    int i = 0;
    for( i = 0; i < nums.size(); i++){
        a = a ^ i ^ nums[i];
    }
    
    return a ^ i;
}

bool hasCycle(ListNode *head) {
    if(head == nullptr) return false;
    unordered_set<ListNode*> s;
    s.insert(head);
    while(head!=nullptr){
        head = head -> next;
        if(s.find(head) == s.end()){
            s.insert(head);
        }
        else return true;
    }
    return false;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size() == 0 ) return nullptr;
    if(nums.size() == 1) return new TreeNode(nums[0]);
    int mid = 0;
    if(nums.size()%2 == 1){
        mid = nums[(nums.size()-1)/2];
    }else{
        mid = nums[(nums.size()+1)/2];
    }
    TreeNode * a = new TreeNode(nums[mid]);
    
    vector<int> leftInts(nums.begin(), nums.begin()+mid);
    vector<int> rightInts(nums.begin()+mid+1, nums.end());
    
    a->left = sortedArrayToBST(leftInts);
    a->right = sortedArrayToBST(rightInts);
    
    return a;
}

void reverseWords(string &s) {
   
    stack<int> word;
    stack<int> sentence;
    int i = 0;
    
    while(i <= s.size()){
        if(i == s.size() || s[i] == ' '){
            if(!word.empty()){
                if(!sentence.empty()){
                    sentence.push(' ');
                }
                while(!word.empty()){
                    sentence.push(word.top());
                    word.pop();
                }
            }
        } else{
            word.push(s[i]);
        }
        i++;
    };
    
    s.clear();
    while(!sentence.empty()){
        s.push_back(sentence.top());
        sentence.pop();
    };
}

void input(TreeNode * root, vector<int> &v){
    if(root == nullptr) return;
    else{
        v.push_back(root->val);
        input(root->left, v);
        input(root->right, v);
    }
}
int kthSmallest(TreeNode* root, int k) {
    vector<int> v;
    input(root, v);
    sort(v.begin(),v.end());
    return v[k-1];

}

int maxProfit(vector<int>& prices) {
 
    if(prices.size() <= 1) return 0;
    vector<int> s0(prices.size(),0);
    vector<int> s1(prices.size(),0);
    vector<int> s2(prices.size(),0);
    
    s0[0] = 0;
    s1[0] = -prices[0];
    s2[0] = 0;
    
    for(int i = 1; i < prices.size();i++){
        s0[i] = max(s0[i-1], s2[i-1]);
        s1[i] = max(s1[i-1], s0[i-1] - prices[i]);
        s2[i] = s1[i-1] + prices[i];
    }
    
    return max(s0[prices.size()-1],s2[prices.size()-1]);
    
    
    
    
    
}



int main(){
    string s =" a";
    reverseWords(s);
    cout << s << " " << s.length() << endl;
    return 0;
}
/*

 */

