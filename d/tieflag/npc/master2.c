
inherit NPC;
inherit F_MASTER;

void create()
{
    	object armor;
    	set_name("日后", ({ "master queen", "master","queen" }) );
    	set("gender", "女性" );
    	set("class","tieflag");
    	set("age", 46);
    	
    	set("cor",50);
    	set("apprentice_available", 50);
    	set("rank_nogen",1);
    	create_family("常春岛", 1, "掌门");
    	set("ranks",({"弟子","小侠女","侠女","大侠女","仙女","神女","圣女",
                      "副掌门"}));

    	set("long",
        	"日后乃铁血大旗门第七代掌门人云翼之妻，因看不惯铁血大旗门人对其\n"
        	"妻子的无情，开创常春岛一派，以收容世上所有伤心女子。\n"
        	);
		set("fly_target",1);
    	
    	set("reward_npc", 1);
    	set("difficulty", 15);
    	set("no_busy",6);
    	set("attitude", "peaceful");
    
    	set("combat_exp", 6500000);
    	set("score", random(90000));
            
    	set_skill("unarmed", 300);
    	set_skill("sword", 200);
    	set_skill("force", 200);
    	set_skill("parry", 200);
    	set_skill("dodge", 200);
    	set_skill("ill-quan", 200);
    	set_skill("jiayiforce", 150);
    	set_skill("tie-steps", 200);
    	set_skill("perception", 250);
    		
    	map_skill("unarmed", "ill-quan");
    	map_skill("force", "jiayiforce");
    	map_skill("dodge", "tie-steps");

    	setup();
    	armor=new(__DIR__"obj/corclot");
    	armor->set_name("天青丝衣",({"cloth"}) );
    	armor->move(this_object());
    	armor->wear();

}

void reset()
{
    delete_temp("learned");
    set("apprentice_available", 20);
}

void attempt_apprentice(object ob)
{
    if( query("apprentice_available") ) {
        if( find_call_out("do_recruit") != -1 )
            command("say 慢著，一个一个来。");
        else
            call_out("do_recruit", 2, ob);
    } else {
        command("say 本掌门今天已经收了二十个弟子，不想再收徒了。");
    }
}

void do_recruit(object ob)
{
/*    if( (string)ob->query("gender") != "女性" )
    {      command("say 我只收女弟子！");
    }
    else {

        command("smile");
        command("say 你入我常春岛，学常春岛武功，今后绝不可与男人纠缠不清！");
        command("smile");
        command("recruit " + ob->query("id") );
    } */
    command("shake");
    command("say 本后闭关练功，暂不收徒");
}

int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "tieflag");
    add("apprentice_availavble", -1);
}
/*
void init()
{
    object me;
    me = this_player();
    if(userp(me) && interactive(me) && me->query("class") == "tieflag" 
       &&  me->query("marry"))
    {
        command("say 大胆！竟敢触犯门规！");
	this_object()->kill_ob(me);
    }
    ::init();
}

*/