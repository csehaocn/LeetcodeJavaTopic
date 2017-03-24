#include<cstdio>
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include<map>
#include<list>
#include<stack>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(int *arr, int size)
{
	if(0 == size)
	{
		return NULL;	
	}

	ListNode* out = new ListNode(arr[0]);
	ListNode* curr = out;

	for(int i = 1; i != size; ++i)
	{
			curr -> next = new ListNode(arr[i]);
			curr = curr -> next;
	}

	return out;
}

std::string ListToString(ListNode* l)
{
   std::stringstream ss; 
   while(NULL != l)
   {
        ss << l->val << " ";  
        l = l -> next;
   }
   return ss.str();
}

template<typename T> std::string vectorToString(const std::vector<T> &t)
{
	std::stringstream ss;
    for(auto it = t.begin(); it != t.end(); ++it)
    {
        ss << *it << " ";
    }
	return ss.str();
}

template<typename T> std::string multVecToString(const std::vector<T> &t, int dimension)
{
	std::stringstream ss;

    if( 1 == dimension )
    {
        ss << vectorToString(t) << std::endl;
    }
    else
    {
        for(auto it = t.begin(); it != t.end(); ++it)
        {
            ss << vectorToString(*it, dimension-1) << " ";
        }
    }

	return ss.str();
}

template<typename T> void pVector(const std::vector<T> &t)
{
    std::cout << vectorToString(t) << std::endl;
}

template<typename T> std::string stackToString(const std::stack<T> &t)
{
	std::stringstream ss;
	std::stack<T> tmp(t);
	while(!tmp.empty())
	{
	ss << tmp.top() << " "; 
    tmp.pop();	
	}
	return ss.str();
}

template<typename keyType, typename valueType> std::string mapToString(const std::map<keyType, valueType> &m)
{
	std::stringstream ss;
	typename std::map<keyType, valueType>::const_iterator iter;
	typename std::map<keyType, valueType>::const_iterator endIter = m.end();
    endIter--;
    for(iter = m.begin(); iter != endIter; ++iter)
    {
        ss << iter->first << "=>" << iter->second << std::endl;
    }
        ss << iter->first << "=>" << iter->second;
	return ss.str();
}

template<typename keyType, typename valueType> void pMap(const std::map<keyType, valueType> &m)
{
        std::cout << mapToString(m) << std::endl;
}

template<typename T> std::string listToString(const std::list<T> &lists)
{
	    std::stringstream ss;
        typename std::list<T>::const_iterator iter; 
        for(iter = lists.begin(); iter != lists.end(); iter++)
            ss<<*iter<<" ";
        return ss.str();
}
