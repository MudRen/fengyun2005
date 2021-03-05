inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int leave();

void create()
{
    	set_name("石雁", ({ "master shi", "master", "shi" }) );
    	set("nickname", "五行真人");
    	set("gender", "男性");
    	set("age", 62);
    	set("long","
石雁乃当今武当掌门，他的太极心法和三才剑法已练到了极高的境界。
他尤其精通太极五行，五行身法已是当世无双，所以人称『五行真人』。\n");
    
    	set("combat_exp", 50000000);
    	set("score", random (20000));

    	set("class", "wudang");
    	
    	create_family("武当派", 57, "掌门人");
    	set("rank_nogen",1);
    	set("ranks",({"道士","小真人","真人","小天师","天师",YEL"大天师"NOR,YEL"副掌门"NOR,
                      HIY"掌门"NOR}));
    	
    	set("fly_target",1);	

    	set("atman", 20000);
    	set("max_atman", 20000);
		set("mana", 20000);
		set("max_mana", 20000);
		set("max_force", 20000);
		set("force", 20000);
    		
    	set("inquiry", ([
        	"太极心法": "太极心法乃道家入门的基本心法，能够调和体内的阴阳二气。\n",
        	"武当派":   "我武当派自张真人开山立派至今，世世代代皆以行侠仗义为己任。\n",
 	 	"leave" : (: leave :),
         ]) );

    
    	set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
    	    	(: cast_spell, "jixing" :),
            	(: perform_action, "sword.nianzijue" :),
             }) );


    	set_skill("unarmed", 160);
    	set_skill("force", 170);
    	set_skill("foreknowledge", 160);
    	set_skill("parry",160);
    	
        set_skill("literate", 100);
    	set_skill("move", 150);
    	set_skill("sword", 200);
    	set_skill("dodge", 150);
    	set_skill("changelaw", 150);
    	set_skill("taiji-sword", 150);
    	set_skill("taijiforce", 150);
    	set_skill("taiji", 150);
    	set_skill("five-steps", 150);
    	set_skill("spells",100);
    	set_skill("qixing",100);
    	set_skill("incarnation",160);
    	set_skill("perception", 100);
    
    
    	map_skill("spells","qixing");
    	map_skill("parry", "taiji-sword");
    	map_skill("sword", "taiji-sword");
    	map_skill("move", "five-steps");
    	map_skill("dodge", "five-steps");
    	map_skill("literate", "changelaw");
    	map_skill("force", "taijiforce");
    	map_skill("unarmed", "taiji");

    	setup();

    	carry_object(__DIR__"obj/msword")->wield();
    	carry_object(__DIR__"obj/mcloth")->wear();
    	carry_object(__DIR__"obj/mhat")->wear();
}


void attempt_apprentice(object ob)
{
    	//command("say 老道要闭关修炼三年，武当暂且不收新徒！\n");
    	//return;
    	
    	if(ob->query("marry")){
		message_vision("$N哼了一声：武当门下，没有拖儿带女的。”\n", 
				this_object(), ob);
		return;
    	} 	   
    	if( (string)ob->query("marks/武当弃徒") )
        	command("say " + ob->query("name") + "！你还有脸回来见我？");
    	else {
        	command("recruit " + ob->query("id") );
    	}

         return;
}

int recruit_apprentice(object ob)
{
    	if( ::recruit_apprentice(ob) )
        	ob->set("class", "wudang");
    	add("apprentice_availavble", -1);
}


int accept_object(object who, object ob)
{
    	object book;

    	if((string)ob->name() != "顾云飞的秘函") return 0;
    	
    	command("say 多谢这位" + RANK_D->query_respect(who));
    	command("say 这本书你留作记念吧。");
    	book = new(BOOKS"skill/wudang_11");
    	if (!book->move(who))
    		destruct(book);
    	return 1;
}


void die()
{
    	object ob;
    	if( !ob = query_temp("last_damage_from") )
        	ob = this_player(1);
    	if(ob) 
        	ob->set_temp("killed_master_shi",1);
    	::die();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_killing", "kill");
}

void greeting(object ob)
{
        object *inv/*,letter*/, *sy_inv, things;
        int i,j;
//      int got_sword = 0;
        if( !ob || environment(ob) != environment() ) return;
        
        if (ob->query_temp("marks/newbie_quest")==1)    {
                message_vision(CYN"$N打了个谒说：“石真人请了，天机老人向道长问好！”\n"NOR,ob);
                message_vision(CYN"
石雁呵呵一笑说：“泰山一别半载，天机怎么有闲去风云城栽培后辈了，
也代老道向他问好！”\n"NOR,this_object());
                tell_object(ob,WHT"\n你完成了天机老人的任务，你的江湖历练丰富了！\n"NOR);
                tell_object(ob,WHT"（使用hp命令可以查看你现在的经验等级状况）\n"NOR);
                ob->add("combat_exp",500);
                ob->delete_temp("marks/newbie_quest");
                REWARD_D->riddle_set(ob,"新手入门",2);
                return;
        }

        if(ob->short() == "武当老掌门(wudang master)") {
        

                if(REWARD_D->riddle_check(ob,"武当掌门") == 5 
                	|| REWARD_D->check_m_success(ob,"武当掌门"))
				{
                for(i=0; i<sizeof(inv); i++)
                if(inv[i]->query("name")=="面具") destruct(inv[i]);
                command("say 天哪！这，这，这是，是，老，老掌门么？\n");
                message_vision("$N突然一口鲜血喷了出来，惊吓得六神出窍，脸色土黑，一头栽倒在地下。\n",
                this_object());
                ob->set_temp("killed_master_shi",1);
                
                sy_inv = all_inventory(this_object());
                for(j=0;j<sizeof(sy_inv);j++){
                        things = sy_inv[j];
                        destruct(things);
                }
	
                sy_inv = all_inventory(ob);

                for(j=0;j<sizeof(sy_inv);j++)
				{
                        things = sy_inv[j];
						if (things->query("fakegender"))
	                        destruct(things);
                }
	
				if (!REWARD_D->check_m_success(ob,"武当掌门"))
					REWARD_D->riddle_set(ob,"武当掌门",6);

                message_vision(CYN"\n神像后一个轻轻柔柔的声音啐道：真是个没用的家伙，武当派上下草包，果然难成大器！\n一道淡青色的微光自布幔后飞出，没入了石雁的太阳穴中，\n紧接着又是浅浅的粉红在你眼前闪过．．．．\n你觉得脸上发凉，伸手一摸，面具竟已破成两半。\n神像后一阵悉悉索索，似乎有人渐渐远去。\n\n"NOR,ob);

				if (!REWARD_D->check_m_success(ob,"武当掌门"))
					tell_object(ob,HIG"\n事情演变成这样，你也始料未及。\n如今说什么都已无用，还是烤了他的肉去见老刀把子吧。\n\n"NOR);

                things = new(__DIR__"obj/cyanneedle");
                things->move(this_object());
                things = load_object("/d/wudang/yinxuanyan");
//                things->shui();
                this_object()->die();
        
        } else {
                command("say 大胆！竟敢化装成老掌门来吓唬老夫！\n");
                kill_ob(ob);
        }

        }
}

int leave() {
	if (this_player()->query("class")!="wudang") return 0;
	message_vision(CYN"$N怒道：不成器的家伙给我滚开！\n"NOR, this_object(),this_player());
	message_vision(CYN"$N说：想走可以，这太极五行的武当秘技你就别想再用了。\n"NOR,this_object(),this_player());
	message_vision(CYN"$N说：以后也别再来见我！\n"NOR,this_object(),this_player());
	return 1;
}


// 凝輕·dancing_faery@hotmail.com
