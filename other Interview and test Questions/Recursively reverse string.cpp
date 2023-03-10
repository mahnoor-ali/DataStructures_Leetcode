string recursive_string_reverse(string str)
{
    if (str.size() <= 1) {
        return str;
    }
    string first_char(1, str[0]);  // string of length 1 with str[0] as the only character
    string last_chars(str.substr(1)); 
    return recursive_string_reverse(last_chars) + first_char;
}
