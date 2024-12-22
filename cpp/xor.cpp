bool xorf(bool a, bool b)
{
    return (a && !b) || (!a && b) ? true : false;   
}

////////////////
bool xorf(bool a, bool b)
{
    return a^b;
}
/////////////
bool xorf(bool a, bool b){
    return a != b;
}
////////////
bool xorf(bool a, bool b)
{
   return a xor b;
}

///////////
bool xorf(bool a, bool b)
{
    return a ? !b : b;
}