#include <cstdio>
#include <iostream>

using namespace std;

bool is_right_md5(string path, string md5sum) {
  FILE *fp;
  char buffer[1024] = {0};

  string md5_cmd = "md5sum ";
  string cmd = md5_cmd + path;
  fp = popen(cmd.c_str(), "r");
  fread(buffer, 1, sizeof(buffer), fp);
  pclose(fp);
  printf("ans: %s",buffer);

  if(buffer[0] == 0) {
    cout << "Unsupported shell command: " << md5_cmd << endl;
    exit(0);
  }

  for(int i = 0; i < md5sum.length(); i++) {
    // cout << md5sum[i] << ":" << buffer[i] << endl;
    if(md5sum[i] != buffer[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  // fp=popen("ssh yypeng@192.168.0.12 \'ls /\'","r");

  string ans = "d41d8cd98f00b204e9800998ecf8427e";
  string path = "./file";
  bool res = is_right_md5(path, ans); 
  string out = res? "right": "wrong";
  cout << out << endl;
  return 0;
}

