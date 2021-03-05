
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("小狐狸", ({ "little fox","fox" }) );
        set("race", "野兽");
        set("age", 1);
        set("gender", "雌性");
		set("str",1);
		set("force_factor",0);
    	set("combat_exp", 1000000);

		set_temp("buffup/evade_amount",999999);

        set("long", "傻呼呼的一只小狐狸。\n");
	set("limbs", ({ "头部", "身体", "前腿", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 1);
	set("chat_msg", ({
                (: ccommand, "emote 抬头看看你，扫了扫尾巴跳到一边。" :),
                (: ccommand, "emote 低下头，自小溪流中喝了一口水。" :),
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
	


		write("傻呼呼的一只小狐狸。
它小模小样的。
它看起来才出生几天，武功看起来好象"+BLU "不堪一击"NOR+"，出手似乎极轻。
它"HIG"看来身上并无丝毫伤痕。"NOR"\n");
		return 1;
	}
	return 0;
}