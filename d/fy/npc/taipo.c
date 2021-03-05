
#include <login.h>
#include <ansi.h>

inherit NPC;

// Whether waiting for a question
int in_ask;
// The four random numbers generated
int* a=({0,0,0,0});
// Whether the question was answered correctly
int right;


void create()
{
	set_name("私塾先生", ({ "private teacher","teacher" }) );
    	set("title",HIY "一题百文"NOR);
	set("long", "只要你可以最先答对他的问题，就有铜板拿呀。\n");
	set("gender", "男性");
	set("age", 70);
	set("NO_KILL","还是留他一条生路吧。\n");
	set("combat_exp", 9000);
	set("score", 0);
	setup();
	carry_object("obj/armor/cloth")->wear();
	in_ask = 0;
}

void init()
{
	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_answer", "answer");

}


void say_again()
{
	if (!right)
 		command("say 这题也许对你们太难了，干脆换几个数吧！");
	in_ask=0;
}

void chat()
{
	int i;
	string oper;

	if( in_ask || random(20) > 10 ) return;
	delete_temp("wrong");
	//GENEREATE 4 RANODOM NUMBERS
        for(i=0;i<4;i++)
         a[i] = random(9)+1;
        oper =chinese_number(a[0])+","+chinese_number(a[1])+","
             +chinese_number(a[2])+","+chinese_number(a[3])+".";
        command("say 你能不能用这四个数算出二十四来？听好了。。。");
        message_vision( HIR "这四个数是：" + oper +" "NOR , this_object());
        message_vision(NOR "请在一分钟内给出答案(answer) \n" , this_object());
        environment(this_object())->set("question", oper);
        in_ask = 1;
        right  = 0;
	call_out("say_again", 60);
}

int CommonFactor(int a, int b)
{
    if(a<b) { a-=b; b+=a; a=b-a; }
    if(b<=0) return 1;
    if(a/b*b==a) return b;
    return CommonFactor(b, a-a/b*b);
}

int Rational(int b, int a)
{
    int c;
    c=CommonFactor(a,b);
    b/=c;a/=c;
    return ((b-1)<<16)+a;
}

int Oper(int a, int o, int b)
{
    int a0,a1,b0,b1;

    a0=a&0xffff;
    a1=(a>>16)+1;
    b0=b&0xffff;
    b1=(b>>16)+1;

    switch(o)
    {
        //Rational operation (a/b)==(b-1)*BASE+a
    case 1:
    case '+': return Rational(a1*b1,a0*b1+b0*a1);
    case 2:
    case '-': return Rational(a1*b1,a0*b1-b0*a1);
    case 3:
    case '*': return Rational(a1*b1,a0*b0);
    case 4:
    case '/': return Rational(b0*a1,a0*b1);
        //default: printf("Error");
    }
}


//check the pairing of brackets, should be 0 if everything is correct
int check_pair(int* bracket)
{
 int i,sum=0;
 for(i=0;i<4;i++)
 {
  sum+=bracket[i];
  if(sum < 0)
    return sum;
 }
 return sum;
}

//check whether correct numbers are used
//in order to check that
// Check 1. MAX, 2. Min, 3. Sum, 4 Product

int check_nums(int *d)
{
 int sum_a=0;
 int sum_d=0;
 int product_a=1;
 int product_d=1;
 int max_a,min_a,max_d,min_d;
 int i;
 max_a=a[0];
 min_a=a[0];
 max_d=d[0];
 min_d=d[0];

 for(i=0;i<4;i++)
 {
  sum_a+=a[i];
  product_a*=a[i];
  sum_d+=d[i];
  product_d*=d[i];

  if(a[i]>max_a)
   max_a=a[i];
  if(d[i]>max_d)
   max_d=d[i];
  if(a[i]<min_a)
   min_a=a[i];
  if(d[i]<min_d)
   min_d=d[i];
  }
  if(max_a==max_d && min_a==min_d && sum_a==sum_d && product_a==product_d)
   return 1;
  else
   return 0;
}

void show(int* d,int* oper,int* bracket)
{
int i;
for(i=0;i<4;i++)
message_vision(chinese_number(d[i])+",",this_player());

for(i=0;i<3;i++)
message_vision(chinese_number(oper[i])+",",this_player());

for(i=0;i<4;i++)
message_vision(chinese_number(bracket[i])+",",this_player());
}


int value(int* d,int* oper,int* bracket,int num)
{
   int result=0;
   int start=-1; //find the bracket start pos
   int end=-1;   //find the bracket end pos
   int i,j,k,temp,temp_oper;
   int pos=-1;  //the position of first * or /
   int* new_d=({0,0,0,0});
   int* new_oper=({1,1,1});
   int* new_bracket=({0,0,0,0});

  if(num==2)
   {
       result=Oper(d[0],oper[0],d[1]);
//    if(oper[0]==1)
//     result=Oper(d[0],'+',d[1]);
//    if(oper[0]==2)
//     result=Oper(d[0],'-',d[1]);
//    if(oper[0]==3)
//     result=Oper(d[0],'*',d[1]);
//    if(oper[0]==4)
//     result=Oper(d[0],'/',d[1]);
   }
   else //more than 2 numbers
   {
    for(i=1;i<num;i++)
    {
     //first place that has ')' or first negative element in bracket
     if(bracket[i]<0)
     {
      end=i; //now go back to find start of that bracket, find '('
      for(j=end-1;j>-1;j--)
       if(bracket[j]>0)
          start=j;
      break;
     }
    }//end assing values for start and end
     if(end==-1) //no bracket exisits
     {
      for(i=0;i<num-1;i++)
      { if(oper[i]>2)
         { pos=i;
           break;}
      }
      if(pos==-1)  //all +'s and -'s
      {
       result=d[0];
       for(i=0;i<num-1;i++)
       { //if(oper[i]==1)
          result=Oper(result,oper[i],d[i+1]);
          //else
          //result=Oper(result,'-',d[i+1]);
       }
      }
      else  //have * or / somewhere but no brackets
      {
          //if(oper[pos]==3)
        temp=Oper(d[pos],oper[pos],d[pos+1]);
        //else
        //temp=Oper(d[pos],'/',d[pos+1]);

       d[pos]=temp;
       for(i=pos;i<num-2;i++)
       {
        oper[i]=oper[i+1];
        d[i+1]=d[i+2];
       }
       result=value(d,oper,bracket,num-1);
      }
     }
     else  //do the bracket stuff
     {
        if (end-start==num-1)
        {
        bracket[start]--;
        bracket[end]++;
        result=value(d,oper,bracket,num);
        }
       else if(end==start+1)
       {
        bracket[start]--;
        bracket[end]++;
        temp=Oper(d[start],oper[start],d[start+1]);
//        if(oper[start]==1)
//         temp=Oper(d[start],'+',d[start+1]);
//        else if(oper[start]==2)
//         temp=Oper(d[start],'-',d[start+1]);
//        else if(oper[start]==3)
//         temp=Oper(d[start],'*',d[start+1]);
//        else if(oper[start]==4)
//         temp=Oper(d[start],'/',d[start+1]);

        d[start]=temp;
        for(i=start;i<num-2;i++)
        {
         oper[i]=oper[i+1];
         d[i+1]=d[i+2];
         bracket[i+1]=bracket[i+2];
        }
        result=value(d,oper,bracket,num-1);
       }
       else if(end==start+2)
       {
        bracket[start]--;
        bracket[end]++;
        if(start==0)
         {
          temp=value(d,oper,bracket,num-1);
          result=Oper(temp,oper[2],d[num-1]);
//          if(oper[2]==1)
//            result=temp+d[num-1];
//          else if(oper[2]==2)
//            result=temp-d[num-1];
//          else if(oper[2]==3)
//            result=temp*d[num-1];
//          else if(oper[2]==4)
//            result=temp/d[num-1];
          }
         else  //( ) from second to fourth
         {
          for(i=0;i<num-1;i++)
          {
           new_d[i]=d[i+1];
           new_bracket[i]=bracket[i+1];
          }
          for(i=0;i<num-2;i++)
          {
           new_oper[i]=oper[i+1];
          }
          d[1]=value(new_d,new_oper,new_bracket,num-1);
          result=value(d,oper,bracket,2);
         }
        }
     }
    }//end else when num>2
   return result;
// Recursively done
}


int do_answer(string arg)
{
	string s,s_numbers;
	int length,i,count,result;

    // status 1: read a new number,
    //           valid input: '(' '1'-'9'
    // status 2: finished a number, (notice, all numbers should be single digit
    //           valid input: ')' + - * /
    // After read in a number, status change 1 to 2
    // After read in a oper, status change from 2 to 1,
       int status;

    // array of 4 numbers in order read from the expression
        int* d=({0,0,0,0});

    // The three operators accociated with four numbers in order,
    // + - * / are 1 2 3 4
        int* oper=({1,1,1});

    // The braket information:
    // ( is consider a 1
    // ) is consider as -1
    // for example:
    // (a+b)+(c+d) is going to be installed as 1 -1 1 -1
    // ((a+b)*c)+d is going to be installed as 2 -1 -1 0
    //  (a)+(b+c)+d is going to be installed as 0 1 -1 0
        int* bracket=({0,0,0,0});

	if( !in_ask || right) return notify_fail("你必须等下一题。\n");
	if(!arg) return notify_fail("指令格式：answer <方程式>\n");
	message_vision( CYN "$N答道：" + arg + "\n"NOR, this_player());

   // Scan the string now, and store it in the arrays
	s=arg;
        length=strlen(s);
        i=-1;  //current position in string
        status=1; //initial status
        count=0; //start with no number

        while( count<5 && i<length-1)
        {
         i++;
        if (status==1)  //read a number, valid input: ( , 1-9
          {
           if(s[i]=='(')
             bracket[count]+=1;
           else if(s[i]>='1' && s[i]<='9')
             { d[count]=s[i]-'0';
               count++;
               status=2; }
           else
            return notify_fail("私塾先生摇摇头道：错！\n");
          }
         else //read an operator, valid input: ) + - * /
          {
           if(s[i]==')')
             bracket[count-1]-=1;
           else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
             { if(count==4)
                 return notify_fail("私塾先生摇摇头道：错！\n");
               if(s[i]=='-')
                oper[count-1]= 2;
               if(s[i]=='*')
                oper[count-1]= 3;
               if(s[i]=='/')
                oper[count-1]= 4;
               status=1; }
           else
             return notify_fail("私塾先生摇摇头道：错！\n");
          } //end if
        }  //end while
       //should have exactly 4 numbers in expression

       if(i < length-1 || status ==1)
         return notify_fail("私塾先生摇摇头道：错！\n");
       if(count<4)
          return notify_fail("私塾先生摇摇头道：错！\n");
       //check bracket pairing
       if(check_pair(bracket)!=0)
          return notify_fail("私塾先生摇摇头道：错！\n");
       if(!check_nums(d))
       {
        s_numbers =chinese_number(a[0])+","+chinese_number(a[1])+","
             +chinese_number(a[2])+","+chinese_number(a[3])+".";
          return notify_fail("私塾先生说道：错！你必须用我给的四个数\n");
       }
       result=value(d,oper,bracket,4);
       if(result!=24)
       {
//          message_vision("数学老师沉思一刻："+s+"等于"+chinese_number(result)+"\n",this_player());
//          return notify_fail(""数学老师说道：错！不等于二十四呀！\n");
	    return notify_fail("私塾先生摇摇头道：错！\n");
       }
       else
       {
		object ob;
          	command("ah sishu");
          	message_vision( CYN "私塾先生搓手叹道：对了！不错不错！我怎么就没想到呢？\n"NOR,this_player());
          	right = 1;
    		ob = new("/obj/money/coin");
    		ob->set_amount(100);
		if (!ob->move(this_player()))
			destruct(ob);
		tell_object(this_player(),"你被奖励了一百文钱。\n");
		this_player()->start_busy(1);
		this_player()->add_temp("timer/24dian",1);
    		if (QUESTS_D->verify_quest(this_player(),"二十四点")
    			 && this_player()->query_temp("timer/24dian")>=2) {
    			this_player()->delete_temp("timer/24dian");
    			QUESTS_D->special_reward(this_player(),"二十四点");
    		}    
          	return 1;
       }
}

