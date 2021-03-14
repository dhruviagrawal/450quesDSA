string reverseWord(string str)
{
   string rev;
   for(int i=str.size()-1;i>=0;i--)
   {
       rev.push_back(str[i]);

   }
       return rev;
}
