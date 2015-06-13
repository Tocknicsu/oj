
void print(stringstream &ss){<br>
    string str;<br>
    getline(ss, str);<br>
    for(int i = 0 ; i < (int)str.size() ; i++)<br>
        cout << hex << (((int)str[i])&255) << ' ';<br>
    ss.seekg(0, ss.beg); <br>
    cout << endl;<br>
}<br>

