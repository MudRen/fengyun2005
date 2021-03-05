//Tie
inherit NPC;
inherit F_VENDOR;
int tell_him();
int tell_him2();
void create()
{
        set_name("李掌柜", ({ "li", "boss li" }) );
        set("gender", "男性" );
        set("age", 33);
        set("long", "俗人居的掌柜，也是俗人居的老板，听说背景很大．．．。\n");
        set("combat_exp", 70000);
        set("attitude", "friendly");
        set("title", "俗人居老板");
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set("vendor_goods", ([
                __DIR__"obj/mijiu":120,
                __DIR__"obj/sg":120,
                __DIR__"obj/sg2":120,
                __DIR__"obj/sg3":120,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
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
        switch( random(10) ) {
                case 0:
                        say(  name()+"笑咪咪地说道：这位"
                                + RANK_D->query_respect(ob)
                                + "，一分钱一分货，您可别嫌咱这贵哦？ \n");
                        break;
                case 1:
                        say( name()+"笑着道：这位"
                                + RANK_D->query_respect(ob)
                                + "，进来喝两盅吧。 \n");
                        break;

        }
}

void reset(){
        set("vendor_goods", ([
                __DIR__"obj/mijiu":120,
                __DIR__"obj/sg":120,
                __DIR__"obj/sg2":120,
                __DIR__"obj/sg3":120,
        ]) );	
	
}