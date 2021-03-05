inherit NPC;
void create()
{
        set_name("轩辕三成", ({ "san cheng" }) );
        set("gender", "男性" );
        set("age", 53);
        set("reward_npc", 1);
	set("difficulty", 4);
	
        set("long", "一个很可怕的人物，武功高绝，行踪诡秘，无论黑白两道的交易，
只要被他知道，就要抽三成，若有人不肯答应，不出三天，就会尸骨无存。\n");
        
        set("combat_exp", 4000000);
	set("attitude", "friendly");
                   
        set("chat_chance", 1);
        set("chat_msg", ({
"轩辕三成围着你转了一圈：最近你好象又有交易了？\n",
"轩辕三成笑道：这个萧十一郎真不量力，还要抽我七成！\n",
                (: random_move :),
        }) );
        set("inquiry", ([
                "萧十一郎" : "哦，我也正在找他。\n",
		"xiao 11" : "哦，我也正在找他。\n",
		"洗钱"	  : "我只收三成。\n",	
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object me, object ob)
{
	int value,amt;
	object painting;
	mapping paint;
	
	if(!ob->query("illegal"))
	{
	        command("grin");
	        command("say 这位" + RANK_D->query_respect(me) + 
"，这就够了三成了吗？");
        	return 1;
        }
        value=ob->query("base_value");
        amt=ob->query_amount();
        value=value*amt;
        value=value*7/10;
	command("hmm "+me->query("id"));
	command("say 这幅画不错，拿去吧。");        
	painting=new(__DIR__"obj/painting");
	paint=painting->query_paint();
	painting->set("name",paint["author"]+"的"+paint["name"]);
	painting->set("long",paint["long"]);
	painting->set("real_value",value);
	painting->move(me);
	return 1;
}
        

