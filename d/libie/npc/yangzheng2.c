#include <ansi.h>

inherit NPC;
void create()
{
        set_name("杨铮", ({ "yang zheng","yang","zheng" }) );
        set("long",
                "一个瘦削、黝黑、沉静，还不到三十岁的汉子，左臂齐肩而断。\n");

        set("attitude", "friendly");
	set("age",32);
        set("str", 80);
        set("cor",70);
        set("agi",50);

        set("con",70);
	set("title", HIW"捕头"NOR);

        set("combat_exp", 4000000+random(1000000));
        set("max_force",3000);
        set("force",3000);
        

	set_skill("unarmed",200);
	set_skill("sword",200);
	set_skill("libie-sword",200);
	set_skill("parry",1000);
	set_skill("dodge",200);
	set_skill("feixian-steps",200);

	map_skill("sword","libie-sword");
	map_skill("dodge","feixian-steps");

        setup();

        carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/tieflag/obj/leavehook")->wield();
}

void heart_beat()
{
	object me,room,yang;
	int msg;
	string file;
	
	yang=this_object();
	room=environment();

	if(msg=query("dying_msg"))
	{
		me=room->query("结局2人物");
		if(msg==5)
			message_vision(YEL"$N呆呆的望着吕素文的尸体，竟没有注意到$n走了进来。\n"NOR,yang,me);
		if(msg==4) {
			message_vision(YEL"$N呓语道：“素文。。我。。胜了。。从此再也没有谁能让我们再离别
了，就算是老天也不可以。。。。”\n"NOR,yang);
		}
		if(msg==3)
			message_vision(YEL"\n$N脸色忽然转为平静，缓缓举起了离别钩，忽然向自己心口插落，$n
大惊失色，正欲打算阻止，却为时已晚。\n"NOR,yang,me);
		if(msg==2)
			message_vision(YEL"\n$N对$n微笑道：“杨某求仁得仁，此生已无憾，只盼"+RANK_D->query_respect(me)+"能将我夫妇二
人合葬在小木屋外黄土处。。\n"NOR,yang,me);
		if(msg==1)
			{
				message_vision(YEL"$N声音越来越小，慢慢的倒在了吕素文的身边。\n"NOR,yang);
				REWARD_D->riddle_done(me,"离别",200,1);
				me->delete("libie");
				me->delete_temp("libie");	// 清除所有挖坑以外的mark，允许重做但是奖励就是第一次的
				
				// RECORD the first one.
				
				file = "/log/riddle/LIBIE_LOG";
				if (file_size(file)== -1)
				{
					log_file("riddle/LIBIE_LOG",
						sprintf("%s(%s) 解开离别结局, %s \n",
						me->name(1), geteuid(me),ctime(time()) ));
					REWARD_D->riddle_done(me,"销魂传人",1000,1);
				}					
				me->set_temp("libie/离别钩_尾声",1);
				yang->die();
			}
		add("dying_msg",-1);
	}
	::heart_beat();
}

void dying(object me)
{
	set("dying_msg",5);
}



void die()
{	object me,corpse,*inv,room;
	int i;

	room=environment();
	if(me=room->query("结局2人物"))
		me->delete_temp("libie/离别钩_目睹最后结局");
	corpse=new("/d/libie/obj/yangcorpse2");
	corpse->move(room);
	inv=all_inventory(this_object());
	i=sizeof(inv);
	while(i--)
		inv[i]->move(corpse);
	message_vision("杨铮死了\n",this_object());
	destruct(this_object());
		
}

