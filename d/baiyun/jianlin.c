//Sinny@fengyun 2003
//All Rights Reserved
inherit ROOM;
object generate_it(int exp,object mail,object me);
object find_env(object ob);

void create()
{
    set("short", "剑林");
    set("long", @LONG
此处虽名为林，却只是一方硕大无比的空旷石岩，三面环山，岩石表面被打磨得
十分光滑，乃是白云城弟子朝夕练剑习武之处，白云城主虽为一极其洒脱，鄙夷世俗
之人，但对门下弟子习武要求极严，因此白云城弟子皆刻苦练剑，不敢有丝毫滞惰，
剑林石壁上插满了各式各样断折的长剑，白云城主有谓：剑于剑士，可谓十指于心。
即便断折的废剑，也要妥善处置。此处名为剑林，实为剑冢。
LONG
    );
    set("exits",
      ([
	"northwest" : __DIR__"jintaoting",
	"southup" : __DIR__"guajianbei",
	"westdown" : __DIR__"qianlonghu",
      ]));

    set("item_desc", ([
    	"石壁": "石壁上插满了各式各样的断剑（broken-sword），你可以试着拔（pull）下来。\n",
    	"岩石": "石壁上插满了各式各样的断剑（broken-sword），你可以试着拔（pull）下来。\n",
    	"rock": "石壁上插满了各式各样的断剑（broken-sword），你可以试着拔（pull）下来。\n",
    	
    	]) );


    set("objects",
      ([
	__DIR__"npc/jiannu" : 1,
      ]));
    set("outdoors", "baiyun");
    set("coor/x",20);
    set("coor/y",-60);
    set("coor/z",10);
    setup();
}

void init()
{
    add_action("do_pull","pull");
}

int do_pull(string arg)
{
    object blood;
    object me = this_player();
    if(!arg || (arg != "broken-sword" && arg != "sword")) return 0;
    	message_vision("$N用尽全身力量，用力一拉！！\n",me);
      	
    if (!me->query_temp("annie/pull_sword") || random(7) || query("sword"))
    {
		message_vision("$N的内力不够．．．累得狂喷鲜血．．．\n",me);
		me->receive_damage("kee",50);
		blood= new("/d/wanmei/obj/blood");
		blood->move(this_object());
		me->set_temp("last_damage_from","在白云剑林用力过度累死了。\n");
		me->set_temp("annie/pull_sword",1);
		return 1;
    }
    message_vision("谁知道断剑只是松松插在壁上，$N用力过猛，惨叫一声，
执着断剑身子向后倒飞了出去，哐铛一声倒在地上，嘴角溢出一丝鲜血。

断剑脱手飞出，尖啸声中窜入云端，也不知道落到哪里去了。\n",me);
    set("sword",1);	
    blood=new(__DIR__"obj/8sword");
    generate_it (8000000,blood,me);
    me->receive_damage("kee",300);
    me->set_temp("last_damage_from","在白云剑林用力过度累死了。\n");
    return 1;
}


object generate_it(int exp,object mail, object me)
{
	object room,*ulist, place, ob;
	int i,m,flag,fdd,num;
	string file, where;
	ulist=objects();
	m=sizeof(ulist);
	flag=1;

	exp = 8000000;
	while (flag)
	{
		i=random(m);

//		write ("attemp ------fdd = " + fdd + "\n");
//		write (sprintf("it is %O\n",ulist[i]));
		
		if (!ulist[i])
			continue;
		if (!environment(ulist[i]) && !ulist[i]->query("short"))	// not a room: something in the planar void
			continue;
		if (sscanf(file_name(ulist[i]),"/adm/%s",file) == 1)	// daemons
			continue;
		if (sscanf(file_name(ulist[i]),"/obj/user#%d",num) == 1)// players
			continue;
		if (sscanf(file_name(ulist[i]),"/obj/login#%d",num) == 1)// players
			continue;
		if (!ulist[i]->query("name"))	// 天知道是什么东西
			continue;
		
		if (!ulist[i]->query("short") && fdd < 3)		// 尽量放在屋子里，这样减少exp的循环, and teach ppl hiding places.
		{
			fdd++;
			continue;
		}

		room=ulist[i];
		
		// 不能在 player身上也不能在 player携带的容器里		
		if (userp(room))	continue;		
		if (objectp(environment(room)) && userp(environment(room)))	
			continue;						
		
		// 这个东西最终应该存在在某一个房间里面，去除那些无环境的NPC					
		ob = find_env(room);				
		if (!ob)	continue;
			
		if (ob->query("no_fight"))			continue;
		if (ob->query("no_death_penalty"))	continue;
		if (ob->query("no_fly"))			continue;	
		if (ob->query("perma_exist"))		continue;
		if (ob->query("no_lu_letter")) 		continue;	// Some rooms are tricky, can't get
					
		where = file_name(ob);
    	if (   where[0..7]=="/d/death"
    		|| where[0..4]=="/d/fy"			// including fy,fycycle,fywall
    		|| where[0..7]=="/d/eren2"
			|| where[0..6]=="/d/maze"
			|| where[0..5]=="/d/wiz"
			|| where[0..9]=="/d/welcome"
			|| where[0..9]=="/d/phoenix"
			|| where[0..8]=="/d/bashan"
			|| where[0..8]=="/d/zhaoze"
			|| where[0..9]=="/d/taoyuan"
			|| where[0..9]=="/d/shanliu"
			|| where[0..2]=="/p/"
			|| where[0..4]=="/obj"
			)
			continue;
								
		// 当这个地方是一个NPC时
		if (room->query("combat_exp"))
		{
			if (room->query("NO_KILL"))					continue;
			if (room->query("vendetta_mark/authority"))	continue;
			if (room->query("possessed"))				continue;
			if (room->query("no_lu_letter"))			continue;
			if (room->query("combat_exp")> 10050000)	continue;	// capped around 10M				
			if (room->query("combat_exp") > exp/10*12 && fdd < 20)
			{
				fdd++;
				continue;
			}

			if (room->query("combat_exp") < exp/10*8 && fdd < 10)
			{
				fdd++;
				continue;
			}
		}
	
		if (room->query("id") == "skeleton" || room->query("id") == "corpse")
			continue;
			
		if (mail->move(room))
		{
			CHANNEL_D->do_sys_channel("sys","move to " + file_name(room) + "\n");
			CHANNEL_D->do_sys_channel("info","据传"+me->name()+"在白云岛掘到一把古剑，却又得而复失。\n");
//			write("move to "+ file_name(room)+"\n");	
			flag=0;
		}
	}
	return mail;

}

object find_env(object ob)
{
	while(ob)
	{
		if(ob->query("coor")) return ob;
		else 
			ob=environment(ob);	
	}
	return ob;
}

int reset(){
	if (!random(20))	set("sword",0);
	::reset();
}

/*

	       (\~~~/)            
	       ( ．．)        

	       (_____)~．      

　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
