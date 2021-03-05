
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("小乌龟", ({ "little turtle","turtle" }) );
        set("race", "野兽");
        set("age", 1);
        set("gender", "雌性");
		set("str",1);
		set("force_factor",0);
    	set("combat_exp", 1000000);

		set("resistance/kee",100);

        set("long", "傻呼呼的一只小乌龟。\n");
	set("limbs", ({ "乌龟壳" }) );
	set("verbs", ({ "bite"  }) );

	set("chat_chance", 1);
	set("chat_msg", ({
                (: ccommand, "emote 慢腾腾地爬来爬去。" :),
                (: ccommand, "emote 把脑袋缩进壳里。" :),
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
	


		write("一只小小小乌龟，背着花纹美丽的壳。
它小模小样的。
它看起来才出生几天，武功看起来好象"+BLU "不堪一击"NOR+"，出手似乎极轻。
它"HIG"看来身上并无丝毫伤痕。"NOR"\n");
		return 1;
	}
	return 0;
}