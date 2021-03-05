#include <ansi.h>
#include <ansi.h>

inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name(HIY"宋嫂鱼"NOR, ({ "song-fish", "fish" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "西湖一带的名菜，用最上品的鱼，最好的厨师，最纯的泉水，最醇的佐料才做得出。
吃起来入口即化，又鲜又嫩，而由香帅的红粉知己宋甜儿做的宋嫂鱼更是香帅的最爱。据说别有功用。\n");
                set("unit", "条");
                set("food_remaining", 5);
                set("food_supply", 0);
                set("material", "food");
        }
        ::init_item();
}


int finish_eat()
{
        object me;
        int max_force;
        int n;
        me = this_player();
        if (!me->query_temp("timer/songfish") ) {
        	max_force = (int) me->query("max_force");
        	message_vision( HIW "$N狼吞虎咽，风卷残云吃完宋嫂鱼，稍倾，只觉浑身经脉通畅，丹田氤氲，
仿佛有了九牛二虎之力。\n"NOR, me);
        	if (me->query("combat_exp")>1000000) n=3;
                else if (me->query("combat_exp")>500000) n=4;
                        else n=5;
        	max_force = max_force * n;
            me->set("force", max_force);
            me->set_temp("timer/songfish",1);
        	destruct(this_object());
        	return 1;
        } else 
        	message_vision( HIW "$N舔了舔唇边，回味无穷。\n"NOR, me);
        destruct(this_object());
        return 1;
}
