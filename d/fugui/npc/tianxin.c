#include <ansi.h>
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("田心", ({ "tian xin", "tian" }) );
        set("gender", "女性" );
        set("age", 14);
	set("title", GRN"俏丫鬟"NOR);
        set("long", "田心是田丝丝的贴身丫鬟，也是最好的朋友，一对小酒窝可爱极了。\n");
        set("combat_exp", 100000);
    
        set("attitude", "friendly");
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set_skill("dodge", 150);
        set_skill("parry", 120);
        set("vendor_goods", ([
                __DIR__"obj/neck1":1,
                __DIR__"obj/neck2":1,
                __DIR__"obj/neck3":1,
                __DIR__"obj/neck4":1,
		__DIR__"obj/hat1":1,
		__DIR__"obj/hat2":1,
		__DIR__"obj/hat3":1,
		__DIR__"obj/pin1":1,
		__DIR__"obj/pin2":1,
		__DIR__"obj/ring1":1,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
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
        switch( random(6) ) {
                case 0:
                       say( "田心抿嘴笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，有什么需要的吗？ 我家大小姐啊，平时\n虽说把杨三爷恨得咬牙切齿，现在可不，杨三爷手头一紧，就把身边平时\n当心肝宝贝样的首饰全拿出来卖了。\n");
                        break;
                case 1:
            say( "田心红着脸小声道：这位"
                             + RANK_D->query_respect(ob)
                             + "，我这可是黄金白银，货真价实，都是\n大小姐的宝贝，要不是...... \n");
                        break;
        }
}

				
