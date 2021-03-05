#include <ansi.h>
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("姬灵燕", ({ "ji lingyan", "ji" }) );
        set("gender", "女性" );
        set("age", 18);
	set("title",WHT "巧手无双"NOR);
        set("long",
"长发光亮如镜，白袍与长发随风而舞，一张苍白的脸，以及一双美丽
而迷茫的眼睛。她有双洁白如玉的手，你很难想象就是这双手，做出
了风云城最美丽的衣服。\n");
		set("combat_exp", 50000);
    	set("str", 20);
        set("attitude", "friendly");
		set_skill("dodge", 100);
        set_skill("parry", 120);
        set("vendor_goods", ([
                __DIR__"obj/m_cloth1":8,
                __DIR__"obj/g_gloves":8,
                __DIR__"obj/m_cloth2":10,
                __DIR__"obj/m_cloth3":10,
                __DIR__"obj/m_cloth4":10,
		__DIR__"obj/m_boots1":7,
		__DIR__"obj/m_boots2":8,
		__DIR__"obj/w_skirt1":8,
		__DIR__"obj/w_skirt2":8,
		__DIR__"obj/w_skirt3":8,
		__DIR__"obj/w_skirt4":10,
		__DIR__"obj/w_girth1":10,
		__DIR__"obj/w_girth2":10,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void reset(){
        set("vendor_goods", ([
        __DIR__"obj/m_cloth1":8,
        __DIR__"obj/g_gloves":8,
        __DIR__"obj/m_cloth2":10,
        __DIR__"obj/m_cloth3":10,
        __DIR__"obj/m_cloth4":10,
		__DIR__"obj/m_boots1":7,
		__DIR__"obj/m_boots2":8,
		__DIR__"obj/w_skirt1":8,
		__DIR__"obj/w_skirt2":8,
		__DIR__"obj/w_skirt3":8,
		__DIR__"obj/w_skirt4":10,
		__DIR__"obj/w_girth1":10,
		__DIR__"obj/w_girth2":10,
        ]) );
	
}


void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(6) ) 
        {
                case 0:
                        say( " 姬灵燕笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，来看看最新款式的衣服吧。 \n");
                        break;
                case 1:
                        say( " 姬灵燕笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，我们这些衣服的手工可是天下无双的，。。。 \n");
                        break;
				case 2:
			say ( " 姬灵燕笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，这里的东西绝对能让你满意。。。 \n");
                       break;
        }
}

				
