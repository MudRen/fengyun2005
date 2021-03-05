// Silencer @ FY4 workgroup. Aug.2004

inherit NPC;
void create()
{
	set_name("赤松", ({ "chi song", "song" }) );
	set("title", "三残喇嘛");
	set("gender", "男性" );
	set("class","lama");
	set("age", 52);
	set("skill_public",1);
	set("int", 30);
        create_family("大昭寺", 21, "弟子");
	
	set("long",
		"赤松本是葛伦高僧的得意大弟子，可是被人陷害。葛伦认为他偷\n"
		"了舍利子，将其逐出师门，囚于此谷，砍了他的双足，逼他说出\n"
		"舍利子的下落。不说出舍利子的下落，永不可回布达拉宫。\n"
		);
       	
       	set("chat_chance", 1);
        set("chat_msg", ({
                "赤松说道：谁帮我找回舍利子，我传他铁布衫神功！\n",
                "赤松说道：云松、云松为了争夺掌门弟子之位，竟然陷害于我！\n"
        }) );

	set("inquiry", ([
		"舍利子": "嗯....舍利子一定是我师妹胭松盗走的。\n",
		"云松": "云松在布达拉宫城的大昭寺里。",
	]) );
	
	set("attitude", "peaceful");
	
	set_skill("iron-cloth", 150);
	
	set_skill("unarmed", 150);
	set_skill("bloodystrike", 120);
	set_skill("force", 150);
	set_skill("bolomiduo", 100);
	set_skill("dodge",120);
	set_skill("parry",120);
	
	map_skill("unarmed", "bloodystrike");
	map_skill("force", "bolomiduo");
	map_skill("parry", "bloodystrike");
	
	set("combat_exp", 1200000);
	setup();
}

int recognize_apprentice(object ob)
{
        if( !ob->query("free_learn/iron-cloth") ){
                say("赤松说道：你只有帮我回布达拉宫，我才会教你....\n");           
                return 0;
        }

        return 1;
}

int accept_object(object who, object ob)
{
//	int bonus;
	if( ob->name() != "舍利子" && ob->name() != "七环禅杖")
	{
	        say("赤松说道：唉，我要的是舍利子....\n");
			return 0;
	}
	
	
	if (ob->name() == "舍利子"&& ob->query("nature")!= "real" )
       {
    		say("赤松说道：唉，你也被普松骗了，这舍利子是假的....\n");
            return 0;
        }
        
	if (ob->name()== "七环禅杖")
	{
		if (!REWARD_D->riddle_check( who,"义助赤松")) 
			return 0;
		else {
			say("赤松大喜：好，这小子也有今天！\n");
			say("赤松说：这位"+ RANK_D->query_respect(who)+"，谢谢你给我捎来这好消息。“\n");
			who->set("free_learn/iron-cloth",1);
		    REWARD_D->riddle_done(who, "义助赤松",50,1);
		    return 1;
			}
     }	else
	 {
			who->set("free_learn/iron-cloth", 1);
			say("赤松说道：好！好！好！太好了！我的冤终于见青天了....\n");
        	REWARD_D->riddle_done(who, "义助赤松",50,2);
			return 1;	
	 }
		return 1;
}


int prevent_learn(object me, string skill)
{
  	if (skill != "iron-cloth")
  	{
      		command("shake");
      		command("say 我可只答应教你铁布衫啊。");
      		return 1;
  	}
  	return 0;
}


int prevent_shown(object me, string skill)
{
	if (me->query("free_learn/iron-cloth")	&& skill == "iron-cloth")
		return 0;
	
	return 1;
}