// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_VENDOR;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("卖菜的", ({ "cai fan","fan" }) );
        create_family("魔教",2,"长老");
		set("class","demon");
		set("group","demon");
		set("gender", "男性" );
        set("age", 40);
        set("long","一个面色青白，神光隐湛的中年人，却在这里卖菜。\n");
		set("combat_exp", 3400000);
        set("attitude", "friendly");
        set("rank_info/respect", "老二哥");
        set("chat_chance", 1);
        set("chat_msg", ({
                "卖菜的笑道：都说菜贩刀菜贩刀，今天让你们见识见识真正的菜贩刀。\n",
        }) );

        set("vendor_goods", ([
                __DIR__"obj/smallvege":11,
                __DIR__"obj/bigvege":22,
                __DIR__"obj/midvege":22,
                __DIR__"obj/tomato":10,
                __DIR__"obj/cucumber":10,

        ]) );
        setup();

		set_skill("dodge",200);
		set_skill("parry",200);
		set_skill("blade",200);
		set_skill("force",200);
		set_skill("moon-blade",200);
		set_skill("meng-steps",200);
		set_skill("wuzheng-force",200);
		set_skill("bat-blade",200);
		set_skill("demon-blade",200);
		set_skill("demon-steps",200);		
		set_skill("demon-force",200);
		set_skill("ittouryu",200);
		set_skill("lianxin-blade",200);
		set_skill("wind-blade",200);
		set_skill("qiusheng-blade",200);
		set_skill("shenji-blade",200);
		set_skill("shenji-steps",200);		
		set_skill("springrain-blade",200);
		set_skill("shortsong-blade",200);
		set_skill("chillblade",200);
		map_skill("blade","moon-blade");
        map_skill("dodge","moon-blade");
        map_skill("parry","moon-blade");

		carry_object("/obj/armor/cloth")->wear();
		carry_object("/obj/item/carver")->wield();
}
void attempt_apprentice(object me)
{
		command("recruit " + me->query("id") );
		return;
	if(REWARD_D->check_m_success(me,"圆月弯刀"))
    		{
    				message_vision("$N看着$n，爽朗地笑了：“你既然与我魔教有缘我就替教主收你入门了”\n", this_object(), me);
    			command("recruit " + me->query("id") );
		}
		command("say "+"你与我教暂时无缘，不如先去历练历练如何");
}
void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}

void reset()
{
	// 因为角色增强，需要reset....以应付初级quest.
        set("vendor_goods", ([
                __DIR__"obj/smallvege":11,
                __DIR__"obj/bigvege":22,
                __DIR__"obj/midvege":22,
                __DIR__"obj/tomato":10,
                __DIR__"obj/cucumber":10,
        ]) );
}



int do_attack() {
	int i = random(10);	
	if (query_busy() > 1)
	{
		start_busy(1);
		return 1;
	}
	else
		stop_busy();
	if (!query_temp("weapon"))
        carry_object("/obj/item/carver")->wield();

	switch(i) {
		case 1: //
			ccommand("enable blade bat-blade");
			map_skill("force","wuzheng-force");
			map_skill("dodge","meng-steps");
			set("class","bat");
			ccommand("perform shiwanshenmo");
			break;
		case 2:	//
			ccommand("enable blade demon-blade");
			map_skill("dodge","demon-steps");
			map_skill("force","demon-force");
			set("class","demon");
			ccommand("perform tiandirenmo");
			break;
		case 3:
			ccommand("enable blade ittouryu");
			set("class","ninja");
			ccommand("perform gobankiri");
			break;
		case 4: // 
			ccommand("enable blade wind-blade");
			ccommand("perform leitingpili");
			break;
		case 5:
			ccommand("enable blade qiusheng-blade");
			set("class","huangshan");
			ccommand("perform jingsheng");
			break;
		case 6:
			ccommand("enable blade shenji-blade");
			ccommand("enable dodge shenji-steps");				
			set("class","shaolin");
			ccommand("perform jichulianhuan");
			break;
		case 7:
			ccommand("enable blade shortsong-blade");
			set("class","legend");
			ccommand("perform duangechangmeng");
			break;
		case 0:
			ccommand("enable blade springrain-blade");
			ccommand("perform dangshimingyue");
			break;
		case 8:
			ccommand("enable blade ittouryu");
			set("class","ninja");
			ccommand("perform hyakki");
			break;
		case 9:
			ccommand("enable blade chillblade");
			set("class","moon");
			delete("timer");
			ccommand("perform mingyue");
			break;
	}

	switch (random(3))
	{
	case 0:
	    message_vision(CYN"\n卖菜的笑道：都说菜贩刀菜贩刀，今天让你们见识见识真正的菜贩刀。\n"NOR,this_object());
		break;
	case 1:
	    message_vision(CYN"\n卖菜的笑道：菜贩刀滋味如何？\n"NOR,this_object());
		break;
	case 2:
	    message_vision(CYN"\n卖菜的笑道：刀，菜刀，菜贩刀，杀菜贩刀，杀过菜贩刀，杀不过菜贩刀。\n"NOR,this_object());
		break;
	}



}
void heart_beat()
{
	::heart_beat();
	if(is_fighting())
			do_attack();
}
