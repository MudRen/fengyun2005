#include <ansi.h>
inherit QUESTNPC;
#include <ansi.h>
void crazy();
void create()
{
        set_name("傅红雪", ({ "fu hongxue","fu" }) );
        set("gender", "男性");
        set("age",26);
        set("nickname", HIC"天涯·明月·刀"NOR);
        set("title", "边城        浪子");
        set("quality","good");
        set("combat_exp", 9000000);
        set("long",
                "他脸上的轮廓英俊而突出，但却像是远山上的冰雪塑成的。\n",
        );
	set("cor",40);
	set("str",50);
	set("cps",31);
        set("max_force",4000);
        set("force",4000);
        set("force_factor",80);
	set_skill("force",150);
	set_skill("demon-force",120);
        set_skill("parry", 200);
        set_skill("blade",200);
        set_skill("dodge",180);
	set_skill("demon-steps",150);
	set_skill("demon-blade",150);
        map_skill("dodge","demon-steps");
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
	map_skill("force","demon-force");
        set("chat_chance", 90);
        set("arrive_msg","走了过来，左脚先迈出一步，右脚才慢慢的拖上去");
        set("leave_msg","走去，左脚先迈出一步，右脚才慢慢的拖上去");
        set("chat_msg", ({
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: crazy :),
	 "傅红雪脸上露出了极其痛苦的表情，喃喃自语道“报仇，报仇！！”\n",
        }) );




        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action,"dodge.lianhuanbabu"  :),
					(:perform_action,"blade.tiandirenmo" :),
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/blackblade")->wield();
}
void remove_effect(int exp);
void crazy()
{	int exp;
	if (!random(10))
	{
		message_vision(
RED"傅红雪的脸忽然扭曲变形，口中吐出白沫。浑身上下都开始痉挛。他眼中露
出了无比痛苦的表情，他似乎想说什么，却一个字也说不出来。。。。。。\n"NOR,this_object());
		exp=this_object()->query("combat_exp");
                this_object()->start_busy(10);
		this_object()->set("combat_exp",2000000);
		call_out("remove_effect",30,exp);
		return;
	}
	return;
}

void remove_effect(int exp)
{
	message_vision("傅红雪的癫痫终于发作完了。\n",this_object());
	this_object()->stop_busy();
	this_object()->set("combat_exp",exp);
}
