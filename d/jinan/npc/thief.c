inherit NPC;
#include <ansi.h>
#include <combat.h>

void smart_fight();
string do_flee();
int d_1();

void create()	
{
                object weapon;
        set_name("司空摘星", ({ "sikong zhaixing","sikong"}) );
        set("nickname", YEL"猴精"NOR);
                set("title",WHT"天下第一神偷"NOR);
        set("gender", "男性" );
    
        set("reward_npc", 1);
        set("difficulty", 1);

                set("env/wimpy",20);

                set("chat_chance", 1);
                set("chat_msg", ({
                        "司空摘星眨眨眼道：我有一个秘密，可是又不能告诉你。\n",
                        "司空摘星抖抖肩膀，笑道：这桥造得好，好凉快，好清爽！\n",
                        "司空摘星转了转眼珠，对你说：想不想学我的本事？去抓一百条蚯蚓．．．\n",
                        "司空摘星臭骂道：死小鸡，臭小鸡，居然又让我来挖蚯蚓。\n",
                        "司空摘星一边趴在地上挖蚯蚓，一边数着：三百二十六，三百二十七．．．\n",
                        "司空摘星碎碎念道：上次有个年轻貌美的女孩子帮我挖蚯蚓，我一高兴啊，什么都教给她了。\n",
                        "司空摘星用沾满泥巴的手扇着风，哀怨道：几天前从老臭虫那里偷来的扇子又不见了。\n",
                        "司空摘星凑近你的耳朵，小声道：其实我这个天下第一，也只比天下第二高那么一点点儿。\n",
                }) );

                set("inquiry",([
        "秘密":         "action"CYN"司空摘星的眉毛和鼻子皱到一起，咳了一声，摇摇头道：我不能告诉你。\n司空摘星转过头去，对着湖里田田的莲花道：猴精憋不住了，猴精要把这个秘密说给莲花精听。\n司空摘星背对着你，伸手指指烟水亭：这亭顶儿尖尖，上边却藏了个人。\n司空摘星道：莲花精你不会轻功，跳不上去，自然找不到那人，猴精可没有泄漏秘密。\n",
        "扇子":         "我记得扇面上写着：踏夜月留香，销魂不知在何方？\n",
        "fan":  "我记得扇面上写着：踏夜月留香，销魂不知在何方？\n",
        "老臭虫":       "我记得扇面上写着：踏夜月留香，销魂不知在何方？\n",
        "bug":  "我记得扇面上写着：踏夜月留香，销魂不知在何方？\n",
        "小鸡":         "还有哪只？还不是那只被雪人西门追着跑的四条眉的臭小鸡。\n",
        "chicken":      "还有哪只？还不是那只被雪人西门追着跑的四条眉的臭小鸡。\n",
        "蚯蚓":         "那些红黄蚯蚓我都不要，只要土红色筷子般粗细的大蚯蚓。\n",
        "worm":         "那些红黄蚯蚓我都不要，只要土红色筷子般粗细的大蚯蚓。\n",
        "天灵翡翠":     (: d_1 :),
        "emerald":      (: d_1 :),
        "弹珠":     (: d_1 :),
        "ball":      (: d_1 :),
        "东边那山":		"action司空摘星扳着指头说：一二三四五，你说东边的山能有几座？\n",
        "mountain":		"action司空摘星扳着指头说：一二三四五，你说东边的山能有几座？\n",
        "树":			"树。。大树。。很大的树。。。。\n",
        "大树":			"树。。大树。。很大的树。。。。\n",
        "tree":			"树。。大树。。很大的树。。。。\n",
                	
        ]) );

		set("age", 34);
        set("per", 40);
        set("int",30);

        set("attitude","friendly");
    
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: smart_fight() :),
             }) );

        set("combat_exp", 6000000);
    
        set_skill("perception", 200);
        set_skill("move", 400);
        set_skill("monkey-claw",200);
        set_skill("dodge", 200);
        set_skill("unarmed",200);
        set_skill("stealing",321);
        set_skill("betting",300);
        set_skill("xifengying",300);
        
        map_skill("unarmed", "monkey-claw");
        map_skill("dodge", "xifengying");

                set("skill_public",1);
        
            setup();

                weapon=carry_object("/obj/armor/cloth");
                weapon->set_name(HIR BLK"破破烂烂沾满灰泥的臭衣衫"NOR, ({ "cloth" }) );
                weapon->set("long","破破烂烂沾满灰泥的臭衣衫(Cloth)。");
                weapon->set("value",0);
                weapon->wear();

}


void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
//                        remove_call_out("greeting");
//                        call_out("greeting", 1, ob);
                }
                add_action("do_steal","steal");
}

int do_steal(string arg)
{
        object me = this_player();
        message_vision("司空摘星拍了拍$N的头，笑道：小家伙，不要鲁班门前弄大斧，关帝君前耍大刀。\n\n",me);
        return 1;
}

int d_1()
{
	object me = this_player();
	if (!me->query("annie/gstone"))
	{
		message_vision(CYN"司空摘星转了转眼珠子：是有那么个东西，可是我为什么要告诉你？\n"NOR,me);
		return 1;
	}
	message_vision(CYN"司空摘星转了转眼珠子：弹珠？我玩腻以后就在东边那山上站得高高的，对着那棵好大好大的树这么一丢～\n"NOR,me);
	if (!REWARD_D->check_m_success(me,"天灵翡翠") && !REWARD_D->riddle_check(me,"天灵翡翠"))
		REWARD_D->riddle_set(me,"天灵翡翠",1);
	return 1;
}

int recognize_apprentice(object ob)
{
        if (!ob->query("free_learn/monkey-claw"))
        {
                message_vision("司空摘星摇摇头道：我要忙着给小鸡抓蚯蚓。\n\n",ob);
                return 0;
        }
    return 1;
}

void greeting(object ob)
{
        object *tar;
        object obj;
        int i,size;

        if( ob->query("combat_exp")< 100000 ) 
                return;

        if( !ob || environment(ob) != environment() ) return;
        say( "司空摘星眼睛滴溜溜的转了一转，拍了拍"+ob->name()+"的肩膀：欢迎，欢迎。\n");

        if (random(15)>2)
                return;

        tar = all_inventory(ob);
        size=sizeof(tar);

        if (size)
        {
                i=random(size);
                obj=tar[i];
                if(!obj->query("no_get") && !obj->query("equipped") && !obj->query("no_drop") && obj->query("name") != "蚯蚓")
                        obj->move(this_object());               
        }
        return;
}
                        
int prevent_learn(object me, string skill)
{
  if (skill != "monkey-claw")
  {
      command("emote 一脸惊吓的看着你说：这个教你了，岂不就有了两个司空摘星？");
      command("emote 把头摇得像拨浪鼓似的：不行，不行。");
      return 1;
  }
  return 0;
}




int kill_ob(object who)
{
        ::kill_ob(who);
        smart_fight();
        return 1;
}


string do_flee()
{
        object me = this_object();
        message_vision(CYN"$N大叫大喊着像一溜青烟般跑走了。\n"NOR,me);
        destruct(this_object());
}

void smart_fight()
{
        object me,target,item;
        object * tar;
        int i;

        if (is_busy())
                return;

        if (environment()->query("short") != "烟水相忘")
        {
                set("chat_chance", 100);
                set("chat_msg", ({
                        (: do_flee() :)
                }) );
                set("env/wimpy",99);
                return;
        }

        me = this_object();
        target = select_opponent();

    tar = all_inventory(target);
        if (sizeof(tar) < 1)
                return;

        for (i=0;i<sizeof(tar) ;i++ )
        {
                item = tar[i];
                if(item->query("name") != "蚯蚓")
                        item->move(me);
        }

        message("vision",HIB"\n一阵微风拂面而过，你似乎看见"+me->name()+"的影子在风中轻轻一晃。\n", environment(me),me);
        message("vision",HIB"你揉揉眼，却发现"+me->name()+"依然还在原地，似乎什么都没有发生。\n\n"NOR, environment(me),me);
        tell_object(target, "你感觉身上一轻，似乎丢了点东西．．\n\n");

        return ;
}


int accept_object(object me, object obj)
{
    if(obj->query("name") == "蚯蚓" && !me->query("free_learn/monkey-claw"))
        {
                me->add("annie/thief_worm",1);
                if (me->query("annie/thief_worm") == 100)
                {
                message_vision("$N拍了拍$n的头，哈哈笑道：不错不错，你果然言而有信。\n",this_object(),me);
                message_vision("$N笑道：来来来，我把我的绝技＂"HIG"猴爪"NOR"＂传授给你。\n",this_object(),me);
                message_vision("$N说道：用"HIG"猴爪"NOR"挖蚯蚓啊，那可是又快又准，灵验无比。\n",this_object(),me);
                        me->set("free_learn/monkey-claw",1);
                        me->delete("annie/thief_worm");
                        return 1;
                }
        message_vision("$N的脑袋点个不停，说道：我还要"+chinese_number(100-me->query("annie/thief_worm"))+"条蚯蚓。\n",this_object(),me);
                obj->move(load_object("/obj/void"));
                return notify_fail(" ");        
        }
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

