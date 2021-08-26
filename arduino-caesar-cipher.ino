String s1;
char s2[256];
char s_correct[256];
int i = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Set password:");
  pinMode(13, OUTPUT);
  i = 0;
}
void loop()
{
  while (Serial.available()==0) {  }
  s1 = Serial.readString();
  s1.toCharArray(s2, 256);
  if(i == 0) 
  {
    copy_string(s_correct, s2);
  }
  i++;
  if(compare(s2, s_correct))
  {
    digitalWrite(13, HIGH);
    delay(3000);
    caesar(s2);
    copy_string(s_correct, s2);
  }
  else
  {
    Serial.print("Wrong password! ");
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
    delay(1000);
    digitalWrite(13, HIGH);
    delay(1000);
    digitalWrite(13, LOW);
  }
  Serial.println("Enter password:");
}

void caesar(char* str)
{
  for(int i = 0; i < length(str); i++)
  {
    char temp = str[i];
    if(isAlpha(temp))
    {
      if(isLowerCase(temp))
      {
      	str[i] = str[i] - 97;
      	str[i] = (str[i] + 1) % 26;
      	str[i] = str[i] + 97;               
      }
      else if(isUpperCase(temp))
      {
      	str[i] = str[i] - 65;
      	str[i] = (str[i] + 1) % 26;
      	str[i] = str[i] + 65;
      }
    }
  }
}
int length(char* str)
{
  int i = 0;
  while(str[i])
    i++;
  return i+1;
}
void copy_string(char* str1, char* str2)
{
  int i = 0;
  while(str2[i])
  {
    str1[i] = str2[i];
    i++;
  }
}
int compare(char* str1, char* str2)
{
  if(length(str1) != length(str2))
  {
    return 0;
  }
  for(int i = 0; i < length(str1); i++)
  {
    if(str1[i] != str2[i])
      return 0;
  }
  return 1;
}

                 
                 