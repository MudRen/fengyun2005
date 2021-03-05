inherit NPC;
int kill_him();

void create()
{
        object armor;
        set_name("过长逊", ({ "guo changxun" }) );
        set("gender", "男性");
        set("age", 39);
        set("long","武当派掌门弟子，着一身藏青色的道袍。\n");
        
        set("inquiry", ([
            "穿颅钉" : (: kill_him :),
        ]));
        
        set("attitude","friendly");
        set("combat_exp", 4500000);
        set("score", 200);
        set("class", "wudang");
       
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({

        }) );
        
        set("no_busy",8);
        
        create_family("武当派", 58, "弟子");

        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("taijiforce", 200);
        set_skill("taiji", 180);
        set_skill("taiji-sword", 180);
        set_skill("five-steps", 200);
        set_skill("taiji",180);

        map_skill("force", "taijiforce");
        map_skill("sword", "taiji-sword");
        map_skill("parry", "taiji");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");
        
        setup();

        carry_object(__DIR__"obj/sword")->wield();
//        carry_object(__DIR__"obj/skinmask2");
        armor=new("/obj/armor/cloth");
        armor->set_name("藏青色的道袍",({"cloth"}) );
        armor->move(this_object());
        armor->wear();

}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="武当派" ) {
                command("nod");
                command("say 进招吧。");
                return 1;
        }
        command("say 武当派不和别派的人过招。");
        return 0;
}

int kill_him()
{
        object me;
        me = this_player();

        if (REWARD_D->riddle_check(me,"古井疑云") != 4
        	&& REWARD_D->riddle_check(me,"古井疑云") != 5)
        {
                command("pure");
                command("dunno");
                return 1;
        }       

        command("emote 脸色一变道：既然你知道了，就与他作伴去吧！\n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        this_object()->set("have_mask",1);        
        REWARD_D->riddle_set(me,"古井疑云",5);
        return 1;
}
 
void die(){
        object /**inv,ob,*/ killer, owner;
//      int i;
        
        if(objectp(killer=query_temp("last_damage_from") ))
        {
        	if ( objectp(owner = killer->query("possessed")))
    		killer = owner;
        
        	if (this_object()->query("have_mask") 
        		&& REWARD_D->riddle_check(killer,"古井疑云") == 5) {
                REWARD_D->riddle_set(killer,"古井疑云",6);
                ::die();
                return;
        	}
        }
        
/*      inv = all_inventory(this_object());
        for(i=0;i<sizeof(inv);i++){
                ob = inv[i];
                if(ob->query("name")== "老掌门的衣服") {
                        destruct(ob);
                }
        }*/
        ::die();
}
