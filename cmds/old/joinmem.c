// memebership key generator
#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{

 int bday,mterm;
 string mid,mmud, mlevel;
 mapping membership;
 string mkey;
 if( !arg ) 
  return notify_fail("指令格式：joinmem <会员启动密码串> \n");
 if((int)me->query("mem_last_try") + 3600 > time())
  return notify_fail("因您上次输入错误，为了保护风云会员的权益，请一小时后再输入密码串。\n");  
 mkey = bicrypt(arg);
 if(sscanf(mkey,"%s@%s-%d-%d-%s",mid,mmud,bday,mterm,mlevel) != 5) {
  me->set("mem_last_try",time()); 
  return notify_fail("对不起，您的会员启动密码串（"+arg+"）不对，
如是输入错误，请一小时后再试，否则请EMAIL：member@fengyun.com\n");
 }
//See if this string is for this user
 if((string)mid != (string)me->query("id"))
  return notify_fail("对不起，您的会员启动密码串（"+arg+"）不对，
如是输入错误，请一小时后再试，否则请EMAIL：member@fengyun.com\n");
 if((string)mmud != INTERMUD_MUD_NAME)
  return notify_fail("对不起，您的会员启动密码串（"+arg+"）不对，
如是输入错误，请一小时后再试，否则请EMAIL：member@fengyun.com\n");
 if((int)mterm < (int)me->query("membership/mterm"))
  return notify_fail("对不起，您的会员启动密码串（"+arg+"）已经作废了。\n");

// Ok, everything seems fine. now let's set his/her status
 me->set("membership/level",mlevel);
 me->set("membership/mterm",mterm+1);
 me->set("membership/start",time());
 write("恭喜您成为风云会的正式成员！关于会员权益，请参看风云家页！\n");
 me->save();
 return 1;
}

int help(object me)
{
	write(@HELP
指令格式：membership <[]|gold|silver|bronze>    

这个指令提供你针对某一主题的详细说明文件，若是不指定主题，则提供你有关
主题的文件。
HELP
	);
	return 1;
}

