//	Silencer@fy4 workgroup

#include <ansi.h>
inherit F_CLEAN_UP;

int main (object me, string arg)
{
	int iron, i,duration;
	string msg;
	string *word;
	string *temp = ({"an", "ba", "hong", "ma", "mi", "ni" });
	
	if (me->query("class")!= "lama")
		return notify_fail("只有大昭弟子才能宣『三字真言』\n");
		
	iron = me->query_skill("kwan-yin-spells",1);
	if (iron < 200)
		return notify_fail("『三字真言』需要200级观音六字明咒。\n");

	if (!arg)
		return notify_fail("你现在准备的三字真言为："+ me->query("marks/pfm/3word")+"\n");
	
/*	if (me->is_busy())
		return notify_fail("你现在正忙，无法静思真言。\n");
				
	if(me->is_fighting() )
		return notify_fail("『三字真言』不能在战斗中记忆。\n");
*/
	
	word = allocate(3);
	
	if (sscanf(arg,"%s+%s+%s",word[0],word[1],word[2])!=3)
		return notify_fail("三字真言设置的格式不对，请参看help 3word\n");
	
	message_vision(HIY"$N"NOR+HIY"跌坐在地，双腿盘拢，合十念道：若复有人，得闻是经，不惊、不怖、不畏，当知是人甚为希有。
何以故？如来说：第一波罗蜜，非第一波罗蜜，是名第一波罗蜜。\n"NOR,me);
	
	for (i=0;i<3;i++){
		if (member_array(word[i],temp)==-1)
			return notify_fail(word[i]+"不是三字真言之一。\n");
		write(" 第" + chinese_number(i+1) +"个真言是：" + word[i] +"\n");	
	}
	
	
	me->set("marks/pfm/3word",arg);
	
	return 1;
}



int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	3word[0m
[0;1;37m────────────────────────────────[0m   

大昭高僧修炼观音明咒到200级以上后，可同时颂出数字真言，
但是，在使用之前必须静思片刻记忆。

格式举例：　3word an+an+an
又如：	   3word an+ni+ni

使用cast 3word 便可将记忆住的真言同时颂出。

对于三字真言来说，耗费的法力最多不超过450，造成的自我忙乱
最多不超过6。

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}