// memebership key generator
#include <ansi.h>
#include <mudlib.h>
#include <membership.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{

 int bday,mterm;
 mapping membership;
 string mkey;
 string mlevel;
 mixed *local;
 // If no argument, let's display this player's membership status
 if( !arg ) {
  write("\n\n");	
  if(mapp(membership=me->query("membership")))  {
   if(membership["start"]+EXP_PERIOD < time()) {
    write("你的风云会员卡已经过期了。如果你想再申请的话请输入：help membership\n"); 
    return 1;
   } else {
// This is where to show all the member status
    if(membership["level"] == "gold") mlevel="金"; 
    if(membership["level"] == "silver") mlevel="银"; 
    if(membership["level"] == "bronze") mlevel="铜"; 
    write(" 你现在是风云"+mlevel+"卡第"+chinese_number(membership["mterm"])+
     "期会员。\n");
    local= localtime(membership["start"]+EXP_PERIOD);
    write(" 你的"+mlevel+"卡将在"+chinese_number(local[5])+"年"+
     chinese_number(local[4]+1)+"月"+chinese_number(local[3])+"号过期。\n");
    write("\n");
   }
  return 1; 
  } else 
  return notify_fail("你现在并不是风云会员，如果你想申请的话请输入：help membership\n");
 }
 bday = (int)me->query("birthday")%10000;
 mterm = (int)me->query("membership/mterm");
 mkey = (string)me->query("id")+"@"+INTERMUD_MUD_NAME+" "+sprintf("%d-%d-",bday,mterm);
 switch(arg) {
  case "gold" :
   mkey += "gold";   
   mlevel = "金";
		break;
  case "silver" :
   mkey +="silver";
   mlevel = "银";
		break;
  case "bronze":
   mkey +="bronze";
   mlevel="铜";
		break;
  default:
   write("风云会员只有金卡（gold），银卡（silver），和铜卡（bronze）会员。\n");
   return 1;
		break;
 }
 write("您的"+mlevel+"卡第"+
  chinese_number(mterm+1)+"期申请号码是：\n"+(string)me->query("id")+"@"+INTERMUD_MUD_NAME+ " "+bicrypt(mkey)+"\n\n"); 
 return 1;
}

int help(object me)
{
	write(@HELP
指令格式：membership <[]|gold|silver|bronze>    

这个指令提供你的会员状况和提供加入风云会所需要的字符串：


HELP
	);
	return 1;
}

