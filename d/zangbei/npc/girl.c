inherit NPC;
#include <ansi.h>

void create()
{
	set_name("洗衣少女", ({ "laundry girl","girl" }) );
	set("gender", "女性" );
	set("cor",20);
	set("age", 18);
	set("long","
沉甸甸的黑色长发，大金色耳环，手臂浑圆，肤色如铜，腰间铜饰叮当，
一条长长的围裙直垂到脚背。\n");
	set("combat_exp", 240000);
	set("attitude", "friendly");
	set("chat_chance",1);
    	set("chat_msg",({
		"\n少女看着河面怔怔地出神，似乎在想什么心事。\n\n"NOR,
    	}) );  
	    		
	set_skill("hammer",200);
	set_skill("dodge",200);
	set_skill("parry",200);
	set_skill("unarmed",200);
		
	setup();
	carry_object(__DIR__"obj/tcloth2")->wear();
	carry_object(__DIR__"obj/l_hammer")->wield();
}

	