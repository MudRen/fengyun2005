inherit SMART_NPC;
#include <ansi.h>

int leave();

int annie_drug()
{
	object me = this_player();
	
	int i;
	i = random(3)+1;


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

	if (me->query_temp("annie/find_herb/叶星士"))
	{
		message_vision(query("name")+"摇头道：我委实不曾听过。\n",me);
		return 1;
	}
	message_vision(query("name")+"沉吟道：明烟草，明烟草．．．医经上并没有载得这味药材啊。\n",me);

	message_vision(query("name")+"说道："+"尽管神医万春流不知下落，听说他远房侄儿还在狼山，你不妨过去打听打听。\n",me);
	me->set_temp("annie/find_herb/叶星士",1);
	return 1;
}


void create()
{
        set_name("叶星士", ({ "ye xingshi", "ye"}) );
        set("nickname", CYN "医仙"NOR);
		set("vendetta_mark","shaolin");
		set("gender", "男性" );
		set("age", 44);
		set("attitude","friendly");
	

		set("long",
	        "叶星士是少林铁扇大帅的唯—俗家弟子，也是江湖中久著盛誉的四大名医之—，\n医术精绝，天下公认，被举为“医仙”。\n"
		);
        set("inquiry",  ([
				"救治剑胆" :  (: leave :),
				"剑胆" :  (: leave :),
				"help" :  (: leave :),
        	"明烟草" : 	(: annie_drug :),
        ]) );
	set("chat_chance", 1);
	set("chat_msg", ({
        name()+"捋捋长髯叹道：无怪叶孤城在此长居，的确是个仙境般的所在。\n",
        "叶星士沉吟半晌苦笑道：叶城主这次把我“请”到白云城，不知究竟为何？\n",
        "叶星士翻了翻手中『黄帝内经』，皱眉道：叶城主眉间微有青黑，难道中了毒？\n",
        }) );
	
    set("combat_exp", 400000);
	
	auto_npc_setup("wang",100,70,0,"/obj/weapon/","fighter_w","taiji",1);
	setup();
    carry_object("/obj/armor/cloth")->wear();
}


int leave()
{
	object room = load_object("/d/baiyun/dragonplace");
	if (REWARD_D->riddle_check(this_player(),"王图一梦") !=5)
		return 0;
	message_vision("$N拱手作揖，告之来龙去脉。\n"NOR, this_player());
	message_vision("$N闻言神色大变道：恕叶某无能，这其中干系太大，这白云剑派的家事。。。\n"NOR, this_object());
	message_vision("$N摇了摇头，白脸涨得紫红道：老衲什么都不知晓，只知世上有些事我等是无能为力的。\n"NOR, this_object());
	REWARD_D->riddle_set(this_player(),"王图一梦",6);

	return 1;
}
