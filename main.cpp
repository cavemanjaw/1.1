//TODO: Wirte methods for c-string type string, std string and also poiner arithmetics

int LengthOfString(char* string)
{
    int lengthOfString = 0;
    //Not really needed, since string var is local and function returns only the lengthOfString var
    char* ptr = string;
    
    while (*ptr)
    {
        //Could be changed to string var, since is is not used anywhere else to be interpreted as the c-string
        ++ptr;
        ++lengthOfString;
    }
    
    return lengthOfString;
}

//For c-strings, char* type of string
bool HasUniqueCharacters(char* string)
{
    int stringLength = LengthOfString(string);
    
    for (int i = 0; i < stringLength; ++i)
    {
        for (int j = i + 1; j < stringLength; ++j)
        {
            if (string[i] == string[j])
            {
                return false;
            }
        }
    }
    
    //Since all chars have been compared there are no the same chars in passed string   
    return true;
}

int main()
{
    char* zmienna = "Kot";
    HasUniqueCharacters(zmienna);
    return 0;   
}