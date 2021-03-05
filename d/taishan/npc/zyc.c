inherit NPC;
inherit F_VENDOR;

int tell_him();

int annie_drug()
{
	object me = this_player();


	if (me->query_temp("annie/find_herb/普生") && me->query_temp("annie/find_herb/百里灵") && me->query_temp("annie/find_herb/万小春") && me->query_temp("annie/find_herb/万春流") && me->query_temp("annie/find_herb/百里雪") && me->query_temp("annie/find_herb/叶星士")	)
	{
		message_vision(query("name")+"疑道：大家都不知道？那……那……\n",me);
		message_vision(query("name")+"突地一拍头笑道：你看我这记性，怎的忘了梅大先生？\n",me);
		return 1;
	}


	if (me->query_temp("annie/find_herb/百里灵"))
	{
		message_vision(query("name")+"摇头道：我委实不记得了。\n",me);
		return 1;
	}
	message_vision(query("name")+"笑道：那不就是……不就是……\n",me);
	message_vision(query("name")+"突地皱眉，轻拍着自己的额头，一字不发。\n",me);
	message_vision(query("name")+"看上去一下子苍老了二十岁，叹气道：老了，老了……\n",me);
	message_vision(query("name")+"说：赛华佗普生常常向我进货，他或许曾从我这里购过明烟草，你去问问吧。\n",me);

	me->set_temp("annie/find_herb/百里灵",1);
	return 1;
}

void create()
{
        set_name("百里灵", ({ "zyc" }) );
        set("gender", "男性" );
	set("title","采药郎");
        set("age", 42);
        set("long", "
他是一位常年隐居深山,终日与药为伴的隐世郎中。曾经踏遍天下名山,尝尽
世间百草。由于常年独居,性情有些古怪,但于医药之道已无所不知。更是治
疗各种绝症的高手。眉宇间隐隐约约透出一丝忧伤,仿佛在思考着什么。\n");
        set("combat_exp", 100000);
        set("attitude", "heroism");
        
        set("skill_public",1);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
	set_skill("dodge", 100);
    	set_skill("herb",100);
    	
    	set("inquiry", ([
        	"明烟草" : 	(: annie_drug :),
	        "zhishang" : (: tell_him :),
	        "治伤" : (: tell_him:),
		"cure" : (: tell_him :),
        ]));
        set("chat_chance", 1);
        set("chat_msg", ({
	"采药郎继续采药，似乎并没有注意你的到来。\n",
        }) );
        set("vendor_goods", ([
		"/obj/medicine/herb_a1" : 30,
		"/obj/medicine/herb_a2" : 30,
		"/obj/medicine/herb_a3" : 30,
		"/obj/medicine/herb_a4" : 30,
		"/obj/medicine/herb_a5" : 30,
		"/obj/medicine/herb_b1" : 30,
		"/obj/medicine/herb_b2" : 30,
		"/obj/medicine/herb_b3" : 30,
//		"/obj/medicine/herb_c1" : 30,
//		"/obj/medicine/herb_c2" : 30,
//		"/obj/medicine/herb_c3" : 30,
//		"/obj/medicine/herb_d1" : 30,
//		"/obj/medicine/herb_d2" : 30,
//		"/obj/medicine/herb_d3" : 30,
//		"/obj/medicine/herb_annie_buff1" : 30,
//		"/obj/medicine/herb_annie_buff2" : 30,
//		"/obj/medicine/herb_annie_buff3" : 30,
//		"/obj/medicine/herb_annie_buff4" : 30,
//		"/obj/medicine/herb_annie_buff5" : 30,
//		"/obj/medicine/herb_dcq" :30,
//		"/obj/medicine/herb_f1" : 30,
//		"/obj/medicine/herb_f2" : 30,
		
	]) );
	setup();
	add_money("coin", 1);
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	::init();
	add_action("do_vendor_list", "list");
}


int tell_him()
{
	object me;
	me =this_player();
	if(!me->query("attr_apply")) {
	message_vision("$N看着$n道：你根本没有伤到筋骨，皮外伤去买些云南白药就可以了。\n",
			this_object(),me);
	return 1;
	} else {
	message_vision("$N看着$n道：你这伤可不轻呀！我能治但是没有寒潭蛙作药引！\n",
                        this_object(),me);
	}
}



int recognize_apprentice(object ob)
{
	command("say 咳，别提了，前两天有个尖嘴猴腮的什么家伙来过，说若是我再瞎出头就砸了我的买卖。\n");
	return 0;
}
		
	
/*	if(ob->query("free_learn/herb"))
	return 1;
        else {
                if (!random(2)) {
                command ("say 想学药道就先帮我做件事，一直听说有个黑瓷药瓮，你能不能替我找一个来？\n");
                } 
		return notify_fail("\n");
	}
}

int accept_object(object who, object ob)
{	
	if (ob->query("name")=="黑瓷药瓮")
	{
		message_vision("$N苦笑着一摊手说：小老儿家里的黑瓷药瓮都堆成山了。\n",this_object());		
		message_vision("$N说：不过，我还需要寒潭蛙作药引，你能不能替我找一下？\n",this_object());
		return 0;
	}	
	if (ob->query("name")=="寒潭蛙")
	{
		if (who->query_temp("well_frog")) {
			message_vision("$N笑呵呵地说：好，好。\n",this_object());		
			message_vision("$N说：想学我的药道？没问题。\n",this_object());
			who->set("free_learn/herb",1);
			return 1;
		} else 
			{
			ccommand("say 这不是你找到的吧，我百里灵不能要来路不明的东西。");
			return 0;
			}
	}	

}*/