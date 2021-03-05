#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

int annie_drug()
{
	object me = this_player();


	if (me->query_temp("annie/find_herb/普生") 
		&& me->query_temp("annie/find_herb/百里灵") 
		&& me->query_temp("annie/find_herb/万小春") 
		&& me->query_temp("annie/find_herb/万春流") 
		&& me->query_temp("annie/find_herb/百里雪") 
		&& me->query_temp("annie/find_herb/叶星士")	)
	{
		message_vision(query("name")+"疑道：大家都不知道？那……那……\n",me);
		message_vision(query("name")+"突地一拍头笑道：你看我这记性，怎的忘了梅大先生？\n",me);
		return 1;
	}


	if (me->query_temp("annie/find_herb/百里雪"))
	{
		message_vision(query("name")+"摇头道：我真的不记得了。\n",me);
		return 1;
	}
	message_vision(query("name")+"颦眉道：这名字．．．似曾在哪里听过．．．\n",me);
	message_vision(query("name")+"摇头道：．．．记不得了，你去问问我叔叔吧。\n",me);
	me->set_temp("annie/find_herb/百里雪",1);
	return 1;
}

int tell_him();
void create()
{
    set_name("百里雪", ({ "baili snow","baili" }) );
    set("gender", "女性" );
    set("title","神农居 小老板");  
    set("nick",HIW"冰雪玲珑"NOR);
    set("age", 22);
    set("long", "百里灵的远方侄女，闲来无事帮唯一的伯父打理神农居。\n");
    set("combat_exp", 100000);
    set("attitude", "friendly");
    set("chat_chance", 1);
    set("chat_msg", ({
	"百里雪小心翼翼称着草药，似乎并没有注意你的到来。\n",
      }) );

	  	set("inquiry", ([
        	"明烟草" : 	(: annie_drug :),
   	]));
	

    set("vendor_goods", ([
//	"/obj/medicine/herb_annie_resurrect1" : 10,
//	"/obj/medicine/herb_annie_resurrect2" : 10,
//	"/obj/medicine/herb_annie_resurrect3" : 10,
//	"/obj/medicine/herb_annie_resurrect4" : 10,
//	"/obj/medicine/herb_annie_resurrect5" : 10,
	"/obj/medicine/herb_a1" : 50,
	"/obj/medicine/herb_a2" : 50,
	"/obj/medicine/herb_a3" : 50,
	"/obj/medicine/herb_a4" : 50,
	"/obj/medicine/herb_a5" : 50,
	"/obj/medicine/herb_b1" : 50,
	"/obj/medicine/herb_b2" : 50,
	"/obj/medicine/herb_b3" : 50,
	"/obj/medicine/lotus"	: 50,

      ]) );
    setup();
    carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
    ::init();
    add_action("do_vendor_list", "list");
}


void reset(){
	    set("vendor_goods", ([	
	"/obj/medicine/herb_a1" : 50,
	"/obj/medicine/herb_a2" : 50,
	"/obj/medicine/herb_a3" : 50,
	"/obj/medicine/herb_a4" : 50,
	"/obj/medicine/herb_a5" : 50,
	"/obj/medicine/herb_b1" : 50,
	"/obj/medicine/herb_b2" : 50,
	"/obj/medicine/herb_b3" : 50,
	"/obj/medicine/lotus"	: 50,
	
      ]) );
}