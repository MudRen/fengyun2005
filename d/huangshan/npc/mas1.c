//TIE@FY3
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight();


void create()
{
    	set_name("李玉函", ({ "master li", "master","li" }) );
    	set("gender", "男性" );
    	set("nickname", HIG"拥翠山庄少主"NOR);
    
    	set("age", 25);
   
    	set("reward_npc", 1);
    	set("difficulty", 30);
    
    	set("apprentice_available", 50);
    	create_family("黄山派", 3, "掌门");
    	set("rank_nogen",1);
    	set("ranks",({"弟子","小侠","少侠","大侠","奇侠","长老","元老","副掌门"}));
    
    	set("long",
        	"李玉函乃天下第一剑客李观鱼之子，出身拥翠山庄，因少年有为而被任为黄山派掌门。\n"
        	);
    	  set("inquiry", ([
                "苍穹神剑" : "家父将古往今来，每一种著名的剑阵都研究过之后，自己也创出一种阵法来，
他老人家认为普天之下，绝没有一个人能破解此阵，但却一直无法证明。这也是他老人家平
生最大的遗憾。要证明这阵法是否真的绝无破绽，就一定要找一个人来破它，他不但要有绝
顶的武功，绝顶的机智，还必须要有非常辉煌的战迹，曾经击败过许多顶尖高手。
 
你若是能破了这个阵，才能证明你配得上这把苍穹神剑。\n",
                "cangqiong" : "家父将古往今来，每一种著名的剑阵都研究过之后，自己也创出一种阵法来，
他老人家认为普天之下，绝没有一个人能破解此阵，但却一直无法证明。这也是他老人家平
生最大的遗憾。要证明这阵法是否真的绝无破绽，就一定要找一个人来破它，他不但要有绝
顶的武功，绝顶的机智，还必须要有非常辉煌的战迹，曾经击败过许多顶尖高手。
 
你若是能破了这个阵，才能证明你配得上这把苍穹神剑。\n",       
       					"破阵":"武当山下，松竹林中，八卦七星，不死不休。\n",
        				"阵":"武当山下，松竹林中，八卦七星，不死不休。\n",
        ]) );
        
    	set("combat_exp", 10000000);
    	set("score", 90000);
    
    	set_skill("unarmed", 200);
    	set_skill("blade", 250);
    	set_skill("force", 180);
    	set_skill("move", 160);
    	
    	set_skill("dodge", 200);
    	set_skill("qiusheng-blade", 200);
    	set_skill("xianjing", 150);
    	set_skill("liuquan-steps", 200);
    	set_skill("parry",200);
    	set_skill("perception",200);

    	map_skill("unarmed", "meihua-shou");
    	map_skill("blade", "qiusheng-blade");
    	map_skill("force", "xianjing");
    	map_skill("dodge", "liuquan-steps");
    	map_skill("parry","qiusheng-blade");	
    	    
    	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );
    
    	setup();
    	carry_object(__DIR__"obj/greencloth")->wear();
    	carry_object(__DIR__"obj/yuhuan")->wield();
}


void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}

void attempt_apprentice(object ob)
{
/*        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say 慢著，一个一个来。");
                else
                        call_out("do_recruit", 2, ob);
        } else {
                command("say 本掌门今天已经收了二十个弟子，不想再收徒了。");
        }
*/
	command("hehe");
	command("say 内子有喜,这学武拜师之事,先放放再说吧");
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "男性" )
          {      command("say 我只收男弟子，你还是去拜我的夫人吧！");
          }
        else {

                command("smile");
                command("say 黄山弟子从来没有背叛师门的。");                
                command("say 你一定要发扬光大黄山派的武功！");
                command("recruit " + ob->query("id") );
                ob->set("once_huangshan",1);                
	}
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huangshan");
        add("apprentice_availavble", -1);
}

int accept_fight(object me)
{
	return 0;
}

void init()
{
	::init();
	add_action("do_get","get");
}

int do_get(string arg)
{
    string what,where;
    object the_wall;
    if(!arg) return 0;
    if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
    the_wall = present(where,environment(this_object())) ;
    if (the_wall)
    if(the_wall->query("name") == "西墙")       
    {
        message_vision("$N对$n大吼一声：大胆！竟敢打先父遗物的主意！\n",
                       this_object(),this_player());
        this_object()->kill_ob(this_player());
        this_player()->start_busy(2);
        return 1;
    }
    return 0;
}


smart_fight()
{
	int i,j,count;
	object *enemy, who;
	who = this_object();
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	if (who->query("kee")<6000) {
		count=0;
		for (j=0;j<sizeof(enemy);j++) {
			if (enemy[j]->is_zombie()) count++;
		}
		if (count>=3)
			command("perform zombie-wp1");
	}
	if (!random(3)&& who->query("kee")>8000) who->perform_action("blade.jingsheng");
	return;
}


int accept_object(object who, object ob)
{
	if(!who->query("marks/黄山送信") || who->query("class")!="legend") return 0; 
	if( ob->query("name")!="铁雪信笺" ) return 0;
		message_vision(CYN"$N微微笑道：多日不见，你师傅还好么？\n"NOR,this_object());
		message_vision(CYN"$N说:一路上辛苦了，在寒舍歇息几天吧，我新招个徒弟，有空你们可以切磋一下。\n"NOR,this_object());
		tell_object(who,HIW"你心中暗喜：好机会！可以乘机学几手了！！\n"NOR);
		who->set("marks/黄山学艺",1);
		who->delete("marks/黄山送信",1);
	return 1;
}