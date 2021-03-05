#include <ansi.h>
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
		set_name("天铭", ({ "tian ming","tian" }) );
        set("gender", "男性" );
        set("age", 14);
		set("title","富贵山庄 "CYN"小侍童"NOR);
		set("nickname","昨天阿离又让我跪算盘");
        set("long","\n");
		set("combat_exp", 50000);
        set("attitude", "friendly");
		
		set_skill("unarmed", 60);
        set_skill("birdiestrike", 50);

		set("inquiry",([
	       	"阿离": 	"唉，就是我家那口子爱迷离啊。\n",
	       	"功夫": 	"王老大的功夫可臭了，我的功夫比他好。\n",
    	]) );

		map_skill("unarmed","birdiestrike");
        set("vendor_goods", ([
                __DIR__"obj/candy":200+random(200),
        ]) );
        setup();
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
		add_action("do_listskill","skills");
}

int do_listskill(string arg)
{
	object me = this_player();
	if (!arg || present(arg,environment()) != this_object())
		return 0;
	if (query("vendor_goods") 
		&& mapp(query("vendor_goods")) 
		&& sizeof(keys(query("vendor_goods"))))
	{
		message_vision("天铭摇了摇头：糖葫芦还没有卖完呢，我回家要跪算盘的。\n\n",me);
		return 1;
	}
	write("天铭目前共学过二种技能：\n\n＊三脚拳 (birdiestrike)                    - "HIB"半生不熟"NOR"  50/    0\n  扑击格斗之技 (unarmed)                   - "HIB"马马虎虎"NOR"  60/    0\n\n");
	return 1;
}



int recognize_apprentice(object ob)
{
	if (query("vendor_goods") 
		&& mapp(query("vendor_goods"))  
		&& sizeof(keys(query("vendor_goods"))))
	{
		message_vision("天铭摇了摇头：糖葫芦还没有卖完呢，我回家要跪算盘的。\n\n",ob);
		return 0;
	}
    return 1;
}


void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(6) ) 
        {
            case 0:
                    say( "天铭扁了扁嘴，委委屈屈的说：什么富贵山庄嘛，穷得叮当响，我连衣服都没得穿。\n");
                    break;
            case 1:
                    say( "天铭叹了口气说：早知道我就过我的百姓生活，谁知道进了山庄，生活反而不比从前轻松。\n");
                    break;
			case 2:
					say ( "天铭认真的看着你说：不，我不是猪。\n");
                   break;
			case 3:
					say ( "天铭向你鞠了个大躬：这位好"
                            + RANK_D->query_respect(ob)
                            + "，可怜可怜我，买两串糖葫芦吧。\n");
                   break;
			case 4:
					say ( "天铭看了看挎着的小篮子，叹气道：还有这么多糖葫芦．．．\n");
                   break;
			case 5:
					say ( "天铭苦着一张小脸，哀怨的说：日上三竿了我一串还没卖出去，回家又要被阿离骂了．．．\n");
                   break;
        }
		if (!random(40))
			say("天铭咬了咬牙，对你说：只要，只要你买光我的糖葫芦，我，我，我就把我的功夫都教给你。\n");
}

				
