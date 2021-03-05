inherit NPC;
void create()
{
        set_name("陆小凤", ({ "lu", "lu xiaofeng" }) );
        set("gender", "男性");
        set("age", 34);
	set("title","心有灵犀一点通");
        set("long","
轮廓分明的脸上，带着满脸风尘之色，但一双眸子却还是明亮的，
眉毛也依旧漆黑，四条眉毛的陆小凤。\n"); 

        set("attitude", "peaceful");
        set("combat_exp", 3000000);
        
        set("no_arrest",1);
        set("reward_npc", 1);
		set("difficulty", 5);
		
	      
		set("skill_public",1);

        set_skill("force", 150);
        set_skill("unarmed", 150);
		set_skill("parry",150);
		set_skill("lingxi-zhi",150);
		set_skill("stormdance",150);
		set_skill("dodge",150);
	
		map_skill("unarmed","lingxi-zhi");
		map_skill("parry", "lingxi-zhi");
		map_skill("dodge", "stormdance");
	
		set_temp("xinyoulingxi", 1);
		
        setup();
		carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	::init();
	
	if (interactive(this_player()) && environment())
	if (environment()->query("lu_cave"))
	    {
	    	REWARD_D->riddle_done(this_player(),"寒冰之窟",10,1);
	    	if (QUESTS_D->verify_quest(this_player(),"见陆小风"))
				QUESTS_D->special_reward(this_player(),"见陆小风");
		}
	
	if (REWARD_D->check_m_success(this_player(), "浴血天牢")
		&& !this_player()->query("free_learn/lingxi-zhi")){
		command("say 多谢相救鹰眼老七。");
		command ("say 无以为报，如不嫌弃，教你些功夫吧。");
		message_vision("$N看了看你道：“只是我的武功非极有恒心及天赋者不能练成。“\n",this_object());
		command ("say 你还是好好想一想吧，比我强的名师还有很多。\n");
		this_player()->set("free_learn/lingxi-zhi",1);
	}						
}

int recognize_apprentice(object ob){
	if ( this_player()->query("free_learn/lingxi-zhi")) {
			return 1;
		}	
	return 0;
}

int prevent_learn(object me, string skill)
{
  	if (skill != "lingxi-zhi" && skill != "unarmed")
  	{
      		command("shake");
      		command("say 我可只答应教你灵犀指啊。");
      		return 1;
  	}
  	return 0;
}


int prevent_shown(object me, string skill)
{
	if (me->query("free_learn/lingxi-zhi") 
		&& (skill == "lingxi-zhi" || skill == "unarmed"))
		return 0;
	
	return 1;
}