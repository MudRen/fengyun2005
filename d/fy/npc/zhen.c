// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>

int leave();

void create()
{
        set_name("甄白木", ({ "zhen baimu","zhen" }) );
		// Useless Item'
        set("gender", "男性" );
        set("age", 41);
        set("title", CYN"如换包假"NOR);
        set("long","这位老板就是江湖上大大有名的「管收管埋」甄白木，在隐退\n江湖之后就来到龙蛇集，依靠做些小本买卖为生。\n据说甄老板当年在"YEL"伪造文书"NOR"上也颇有一手，还曾因此被官府中人\n围剿，如今早已洗手不干。\n");
        set("combat_exp", 900000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ([  
                __DIR__"obj/sp_pic"           	: 40,
                __DIR__"obj/sp_bottle"          : 40,
                __DIR__"obj/sp_clock"           : 40,
                __DIR__"obj/sp_carpet"		: 40,
                BOOKS"yuputuan":		2,
                BOOKS"jinpingmei":		2,
        ]) );
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
		set_skill("lingxi-zhi",100);
		set("forger",1);
		map_skill("unarmed","lingxi-zhi");
		// 第一个用lx-zh的quest? *snicker

			set("inquiry",([
        		"伪造文书": (: leave :),
    		]) );



        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
}

int leave()
{
	object me/*,obj*/,*o;
	int i;
//	string msg;
	me=this_player();

	o = all_inventory(me);
	for (i=0; i<sizeof(o); i++)
	{
		if (crypt(o[i]->query_weight()+"","Bj7mJPd4q6Pbk") != "Bj7mJPd4q6Pbk" 
			|| me->query_temp("annie/fy_zhen"))	continue;
		if (!query_temp("showed_miling"))	continue;		
		ccommand("hmm");
		ccommand("say 既是此物．．．我便重操旧业一回。");
		ccommand("emote 沉思道：现在的官儿是谁了。。。？");
		ccommand("emote 从"+me->name()+"袖中取过一物，转身走到一旁。\n片刻之后，");
		ccommand("emote 将那东西小心翼翼地塞给"+me->name()+"，点了点头道：切记，切记，此物仅你可用。");
		o[i]->add("re"+"al",1);
		me->set_temp("annie/fy_zhen",1);
		delete_temp("showed_miling");
		return 1;
	}

	ccommand("hehe");
	ccommand("say 您真会说笑，小老儿不干这事已经十多年啦。");
	ccommand("say 客官还是看看小老儿的货品吧，样样齐全，包您满意。");
	return 1;
}


void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
		
		// 偶不知道这种地方老板素怎样吆喝说>"<

        return;
}

void reset()
{
        set("vendor_goods", ([
                __DIR__"obj/sp_pic"           : 40,
                __DIR__"obj/sp_bottle"           : 40,
                __DIR__"obj/sp_clock"           : 40,
                __DIR__"obj/sp_carpet"		  : 40,
                BOOKS"yuputuan":		2,
                BOOKS"jinpingmei":		2,
        ]) );
}
