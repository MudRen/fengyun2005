
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("高山野兔", ({ "rabbit" }) );
        set("race", "野兽");
        set("age", 1);
        set("gender", "雌性");
		set("str",1);
		set("force_factor",0);
    	set("combat_exp", 1000000);

        set("long", "一只活泼好动的高山野兔，正竖着大耳朵盯着你。\n");
		set("limbs", ({ "兔尾巴" }) );
		set("verbs", ({ "bite"  }) );



		set_temp("buffup/backfire","all");
		set_temp("buffup/backfire_amount",400);
		set_temp("buffup/backfire_msg",HIY"$N"HIY"身上的兔毛四散飞舞，刺得$n"HIY"极不舒服。"NOR);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
					(: ccommand, "pain" :),
        }) );

		set("chat_chance", 1);
		set("chat_msg", ({
					(: ccommand, "lick" :),
					(: ccommand, ":).." :),
		}));
    set("intellgent",1);

	setup();
}
void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
if (!arg)
	return 0;
	if(present(arg,environment()) == this_object()){
	


		write("一只活泼好动的高山野兔，正竖着大耳朵盯着你。
它小模小样的。
它看起来才出生几天，武功看起来好象"+BLU "不堪一击"NOR+"，出手似乎极轻。
它"HIG"看来身上并无丝毫伤痕。"NOR"\n");
		return 1;
	}
	return 0;
}