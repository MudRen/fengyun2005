#include <ansi.h>
inherit F_CLEAN_UP;

string *gifts=({ "gin","kee","sen" });
string *gifts1=({"atman","force","mana"});

int main(object me, string str)
{
        int i;
        object obj;

        if( !str || str == "")
                obj = me;
        else if ( !obj = present(str,environment(me)))
            return notify_fail("对象错误: 找不到"+str+"\n");

        if (!wizardp(me) && me->is_fighting())
        	return notify_fail(HIG"清风对你摇了摇小指：小朋友，这样是不对的噢！\n"NOR);
    
    	if (wiz_level(me)<4 && obj!=me )
			return notify_fail("你只能恢复自己的气血。\n");    		
    
        for( i = 0; i < sizeof(gifts); i++ )
        {
                obj->set(gifts[i],obj->query("max_"+gifts[i]));
                obj->set("eff_"+gifts[i],obj->query("max_"+gifts[i]));
        }
        for( i = 0; i < sizeof(gifts1); i++ )
        {
             obj->set(gifts1[i],obj->query("max_"+gifts1[i])*2);
        }
        obj->set("food",obj->max_food_capacity());
        obj->set("water",obj->max_water_capacity());
        obj->status_msg("all");
        obj->force_status_msg("all");
        obj->clear_condition();
        write("恢复成功。\n");
        return 1;
}

int help(object obj)
{
  write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m巫师指令格式 : 	full	[0m
[0;1;37m────────────────────────────────[0m  

利用此指令可完全恢复生物的状态并清除一些condition。

[0;1;37m────────────────────────────────[0m
HELP
    );
    return 1;
}


