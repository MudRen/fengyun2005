inherit NPC;

void create()
{
        set_name("孙天灭", ({ "fighter", "taoist fighter" }) );
        set("nickname", "六指小真人");
        set("gender", "男性");
        set("age", 20);
        set("long","孙天灭外号六指小真人，据说是丁乘风最喜爱的徒弟，尽得师傅真传！
可不知道为什么被派到这里来看大门。\n");
        set("combat_exp", 100000);
        set("score", 500);
        set("class", "taoist"); 
        set("possessed",1);
	
        set("inquiry", ([
                "谷衣心法": 
"谷衣心法是我茅山派为对抗邪魔外道所创的内功心法。\n",
        ]) );
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "drainerbolt" :),
                (: cast_spell, "invocation" :),
        }) );

        create_family("三清宫", 6, "弟子");
        
        set_skill("magic", 50);
        set_skill("move", 50);
        set_skill("force", 50);
        set_skill("spells", 90);
        set_skill("unarmed", 50);
        set_skill("parry", 60);
        set_skill("dodge", 80);
        set_skill("gouyee", 90);
        set_skill("taoism", 80);
        set_skill("necromancy", 80);    
	set_skill("tenderzhi",50);
	set_skill("notracesnow",120);
	
	map_skill("dodge","notracesnow");
	map_skill("unarmed","tenderzhi");
        map_skill("force", "gouyee");
        map_skill("spells", "necromancy");

        set_temp("apply/dodge", 20);
        set_temp("apply/armor", 20);

        setup();
        carry_object("/obj/armor/cloth")->wear();

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="三清宫" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 三清宫不和别派的人过招。");
        return 0;
}
 

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/

