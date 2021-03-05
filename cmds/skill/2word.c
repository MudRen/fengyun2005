//	Silencer@fy4 workgroup

#include <ansi.h>
inherit F_CLEAN_UP;

int main (object me, string arg)
{
	int iron, i,duration;
	string msg;
	string *word;
	string *temp = ({"an", "ba", "hong", "ma", "mi", "ni" });
	string *ctemp = ({"『唵』","『叭』","『哞』","『嘛』","『咪』","『呢』"});
	
	if (me->query("class")!= "lama")
		return notify_fail("只有大昭弟子才能宣『二字真言』\n");
		
	iron = me->query_skill("kwan-yin-spells",1);
	if (iron < 170)
		return notify_fail("『二字真言』需要170级观音六字明咒。\n");

	if (!arg)
		return notify_fail("你现在准备的二字真言为："+ me->query("marks/pfm/2word")+"\n");
	
/*	if (me->is_busy())
		return notify_fail("你现在正忙，无法静思真言。\n");
			
	if(me->is_fighting() )
		return notify_fail("『二字真言』不能在战斗中记忆。\n");
*/
	
	word = allocate(2);
	
	if (sscanf(arg,"%s+%s",word[0],word[1])!=2)
		return notify_fail("二字真言设置的格式不对，请参看help 2word\n");
	
	message_vision(HIY"$N"NOR+HIY"跌坐在地，双腿盘拢，合十念道：一切有为法　如梦幻泡影  如露亦如电　应作如是观\n"NOR,me);
	
	for (i=0;i<2;i++){
		if (member_array(word[i],temp)==-1)
			return notify_fail(word[i]+"不是可记忆的六字真言之一。\n");
		write(" 第" + chinese_number(i+1) +"个真言是：" + word[i] +"\n");	
	}
		
	me->set("marks/pfm/2word",arg);
	
	
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	2word[0m
[0;1;37m────────────────────────────────[0m   

大昭高僧修炼观音明咒到170级以上后，可同时颂出数字真言，
但是，在使用之前必须静思片刻记忆。

格式举例：　2word an+an
又如：	   2word an+ni

使用cast 2word 便可将记忆住的真言同时颂出。

对于二字真言来说，耗费的法力最多不超过350，造成的自我忙乱
最多不超过4。

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}