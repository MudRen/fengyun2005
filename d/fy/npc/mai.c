// annie 07.2003
// dancing_faery@hotmail.com

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
        set_name("麦贾惑", ({ "mai jiahuo","mai" }) );
		// MARK' collection
        set("gender", "男性" );
        set("age", 31);
        set("title", CYN"如假包换"NOR);
        set("long","这位老板姓麦，名叫贾惑，是龙蛇集第一大摊的摊主。\n他的摊上从来不缺各种希奇古怪的玩意，只是价格都令人乍舌。\n尽管如此，自愿上钩的鱼儿仍然很多，光顾贾惑摊的人是络绎不绝。\n");
        set("combat_exp", 150000);
        set("attitude", "friendly");
        set("per",30);
        set("vendor_goods", ([  
                __DIR__"obj/sp_rabbitmeat"    : 40,
//                __DIR__"obj/sp_pic"           : 40,
                __DIR__"obj/sp_leaf"          : 40,
                __DIR__"obj/sp_ting"          : 40,
                __DIR__"obj/sp_needlebag"     : 40,
                __DIR__"obj/sp_wine"		  : 40,
                __DIR__"obj/sp_map"			  : 40,
                __DIR__"obj/sp_conch"			  : 40,
//                __DIR__"obj/sp_carpet"		  : 40,
        ]) );
        set_skill("unarmed",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set("inquiry", ([
                "假货" : "action麦贾惑瞪大了眼珠猛摇头：不不不，我麦贾惑从来不卖假货！",
               "卖假货" : "action麦贾惑瞪大了眼珠猛摇头：不不不，我麦贾惑从来不卖假货！",
        ]));
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
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
                __DIR__"obj/sp_rabbitmeat"    : 40,
//                __DIR__"obj/sp_pic"           : 40,
                __DIR__"obj/sp_leaf"          : 40,
                __DIR__"obj/sp_ting"          : 40,
                __DIR__"obj/sp_needlebag"     : 40,
//                __DIR__"obj/sp_carpet"		  : 40,
                __DIR__"obj/sp_map"			  : 40,
                __DIR__"obj/sp_wine"		  : 40,
                __DIR__"obj/sp_conch"			  : 40,
        ]) );
}

