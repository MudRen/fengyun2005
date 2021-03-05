// copyright apstone, inc 1998
inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("买买提", ({ "waiter" }) );
        set("gender", "男性" );
        set("age", 70);
        set("long",
                "一个满脸朴实，散发着古铜色光芒的老人。\n");
	set("combat_exp", 5000);
        set("attitude", "friendly");
        set("rank_info/respect", "老人家");
        set("vendor_goods", ([
                __DIR__"obj/milk2": 120,
                __DIR__"obj/milk": 120,
                __DIR__"obj/soda": 120,
		__DIR__"obj/soda2" : 120,
        ]) );
        setup();
        carry_object(__DIR__"obj/hat")->wear();
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
        switch( random(3) ) {
                case 0:
                        say( "买买提笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，亚克西姆赛斯。\n");
                        break;
                case 1:
                        say( "买买提抬起他古铜色的脸，说道：这位" + RANK_D->query_respect(ob)
                                + "，嗨里霍西。\n");
                        break;
                case 2:
                        say( "买买提说道：这位" + RANK_D->query_respect(ob)
                                + "，过火焰山可要有些酒水才可以上路哟！\n");
                        break;
        }
}

void reset(){
	set("vendor_goods", ([
                __DIR__"obj/milk2": 120,
                __DIR__"obj/milk": 120,
                __DIR__"obj/soda": 120,
				__DIR__"obj/soda2" : 120,
        ]) );
	
}