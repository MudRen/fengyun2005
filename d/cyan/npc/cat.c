#include <ansi.h>
inherit NPC;
void create()
{
    	set_name("小山猫", ({ "little cat", "cat" }) );
        set("race", "野兽");
        set("age", 1);
        set("gender", "雌性");
        set("long", "一只小小的，有着黄白花纹的小猫，正趴在溪边好奇的拍打着水花。\n");
    	set("combat_exp", 20000000);
    	set("max_kee",500);
    	set("max_gin",500);
    	set("max_sen",500);
		set("str",1);
		set("force_factor",0);
        set("attitude","peaceful");
        set("limbs", ({ "头部", "身体","尾巴" }) );
    	set("verbs", ({ "bite","claw" }) );
		set("chat_chance", 1);
		set("chat_msg", ({
			"小山猫好奇的抬头看看你。\n",
			"小山猫绕着你的脚走了一圈，在你身上嗅来嗅去。\n",
			"小山猫偏过头看着你，抬起爪子指指溪水。\n",
		}));	
        setup();
}

int accept_object(object who, object ob)
{
    if(ob->query("marks/catfood"))
    {
        message_vision(sprintf(
            "$N走了过来，舔舔你的手把%s叼走了。\n", ob->name()),this_object());
        return 1;
    }
	return notify_fail("小山猫低头嗅了嗅，转身跳了开去。\n");
}
        
void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
if (!arg)
	return 0;
	if(present(arg,environment()) == this_object()){
		write("一只小小的，有着黄白花纹的小猫，正趴在溪边好奇的拍打着水花。
它小模小样的。
它看起来才出生几天，武功看起来好象"+BLU "不堪一击"NOR+"，出手似乎极轻。
它"HIG"看来身上并无丝毫伤痕。"NOR"\n");
		return 1;
	}
	return 0;
}