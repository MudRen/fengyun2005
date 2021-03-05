// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ITEM;
void create()
{
	set_name( "浑身布满经络图的铜人", ({ "copperman","man"  }) );
	set("unit", "个");
	set("no_get",1);
	set("value",20);
	set("long","
这是一个浑身布满经络图的铜人，在铜人的[31m心（ｈｅａｒｔ）[32m，
[1;32m肝（ｌｉｖｅｒ）[0;32m，[33m胃（ｓｔｏｍａｃｈ）[32m，[37m肺（ｌｕｎｇ）[32m，
[34m肾（ｋｉｄｎｅｙ）[32m的部位各有一小孔，在铜人的丹田之处还有
个很深的掌印（ｍａｒｋ）．
\n");
	set_weight(5000);
	::init_item();
}
void init()
{
	add_action("do_touch","touch");
}

int closepath()
{
        object env;
        env = environment(this_object());
        if( !env->query("exits/north") ) return 1;
        message("vision","铜人又动了起来，转回到原来的位子．．．\n",env );
		env->delete("exits/north");
}
int open_path()
{
        object env;
        env = environment(this_object());
        if( !env->query("exits/north"))
        {
	        env->set("exits/north",AREA_QIANFO"tianwang");
		message("vision","铜人眼睛忽然睁开，动了起来，露出了身后的暗道！！\n",env);
	        call_out("closepath",5);
        }
        return 1;
}

int check_needles()
{
	object liver,kidney,stomach, heart, lung, env,*inv;
	object red,green,yellow, white,black;
	env = environment(this_object());
	if(!objectp(liver=present("liver",env))) return 0;
	if(!objectp(kidney=present("kidney",env))) return 0;
	if(!objectp(stomach=present("stomach",env))) return 0;
	if(!objectp(heart=present("heart",env))) return 0;
	if(!objectp(lung=present("lung",env))) return 0;
	
	inv = all_inventory(liver);
		if( sizeof(inv) != 1) return 0;
		green = inv[0];
		if((string)green->query("name") != "绿色的细针" && green->query("name") != "淡绿色的细针" ) return 0;
        
    inv = all_inventory(kidney);
        if( sizeof(inv) != 1) return 0;
        black = inv[0];
        if((string)black->query("name") != "黑色的细针" && black->query("name") != "淡黑色的细针") return 0;
    
    inv = all_inventory(stomach);
        if( sizeof(inv) != 1) return 0;
        yellow= inv[0];
        if((string)yellow->query("name") != "黄色的细针" && yellow->query("name") != "淡黄色的细针") return 0;
    
    inv = all_inventory(heart);
        if( sizeof(inv) != 1) return 0;
        red= inv[0];
        if((string)red->query("name") != "红色的细针" && red->query("name") != "淡红色的细针") return 0;
    
    inv = all_inventory(lung);
        if( sizeof(inv) != 1) return 0;
        white= inv[0];
        if((string)white->query("name") != "白色的细针" && white->query("name") != "淡白色的细针") return 0;
// now we have everything, let's open path! and reset this room;
		red->move(env); destruct(red);
        green->move(env); destruct(green);
        yellow->move(env); destruct(yellow);
        white->move(env); destruct(white);
        black->move(env); destruct(black);
	open_path();
	return 1;
}

int do_touch(string arg)
{
        object me,env;
        if( !arg ) return 0;
        if( arg != "掌印" && arg != "mark") return 0;
        me = this_player();
        if((int) me->query("force") < 50) {
        	write("你的内力不够（需50点内力）！\n"); 
            return 1;
        }
        me->add("force",-50);
        
        message_vision("$N将一股内力送入铜人体内．．．\n",me);
        // if there is needles 
        if(!check_needles() ) {
	        REWARD_D->riddle_done(me,"五行铜人",10,1);		
			if(!me->query_temp("marks/copperman"))
				me->set_temp("marks/copperman",1);
			open_path();
			return 1;
		}
		
        // No needles
                
        
	// for non-xingguo players, each login only need insert needles once.
		if( me->query_temp("marks/copperman")) {
            open_path();
            return 1;
        }
        
        // for xingguo students, it needs 200 force w/o needles
        if( me->query("class")=="bonze") {
            env = environment(this_object());
            message("vision","铜人眼睛忽然睁开，动了起来，露出了身后的暗道！！\n",env);
			message_vision("$N一纵身进了暗道，铜人在$N身后又合上了。\n",me);
			me->move("/d/qianfo/tianwang");
            return 1;
        }

        message_vision("在$N气力已竭的瞬间，铜人眼睛似乎将要睁开！！\n",me);
        return 1;
}
