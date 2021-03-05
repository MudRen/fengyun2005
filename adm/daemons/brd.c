// Apr.08 by Silencer
// Process time is changed to once per 7 days to save the system process time
// Clean up house every half year.

#include <ansi.h>

inherit F_DBASE;

#define DAY 86400*7

void process();

void create()
{
  	set("channel_id","枕霞之城(Residence Area)");
  	seteuid(getuid());
  	remove_call_out("process");
  	call_out("process",DAY);	// 保证不会因为几个update而使得屋子混乱
}


int new_x(int x,string dir);
int new_y(int y,string dir);
int new_z(int z,string dir);


void buildroom(object me,object gold, int flag,string s_title,string l_title, string dir,int tflag,int gc,int sc,int spa,int w)
{
mapping pairs = ([
        "north":                "south",
        "south":                "north",
        "east":                 "west",
        "west":                 "east",
        "northup":              "southdown",
        "southup":              "northdown",
        "eastup":               "westdown",
        "westup":               "eastdown",
        "northdown":    	"southup",
        "southdown":    	"northup",
        "eastdown":             "westup",
        "westdown":             "eastup",
        "northeast":    	"southwest",
        "northwest":    	"southeast",
        "southeast":    	"northwest",
        "southwest":    	"northeast",
        "up":                   "down",
        "down":                 "up"
]);

	object env;
	string this_file;
	string my_file;
	string name;
	string c_name,o_name;
	name = (string)me->query("id")+sprintf("%d",time());
//ready to build!!!

// STEP1: Process the room we are currently in.
//			This step will modify the tree_room file exits
//			Let's read in the .o file so we can save that file

	seteuid(getuid());
	
	c_name = base_name(environment(me))+".c";
    o_name = base_name(environment(me))+".o";
	this_file = read_file(o_name);
//	this_file = read_file(c_name);
	this_file = replace_string(this_file,"set(\"exits\", ([",
"set(\"exits\", ([\n"+"\""+dir+"\""+" : __DIR__"+"\"userroom/"+name+"\",");	
//do NOT change this write_file
    if(!write_file(o_name,this_file,1)){
		tell_object(me,"房屋创建失败，请立即通知巫师，失败代码Room_1001\n");
		return;
	}

#ifdef	ENCRYPTED_WRITE	
	if(!write_file2(c_name,this_file,1)){
		tell_object(me,"房屋创建失败，请立即通知巫师，失败代码Room_1002\n");
		return;
	}
#endif

#ifdef  NONENCRYPTED_WRITE
	if(!write_file(c_name,this_file,1)){
		tell_object(me,"房屋创建失败，请立即通知巫师，失败代码Room_1003\n");
		return;
	}
#endif	
	
	environment(me)->set("exits/"+dir,"/p/residence/userroom/"+name);	
	
// STEP 2: Make the created user_room

//	Exits	
	my_file = read_file("/obj/selfmake/rooms/USER_ROOM.o");
	if (!tflag)		//tflag is defaulted to 1 in fy2005 room system
	{
	my_file = replace_string(my_file,
"set(\"exits\", ([",
"set(\"exits\", ([\n"+"\""+pairs[dir]+"\""+" : "+"\""+c_name+"\",");
	}
	else
	{
		my_file = replace_string(my_file,
"set(\"exits\", ([",
"set(\"exits\", ([\n"+"\""+"out"+"\""+" : "+"\""+c_name+"\",");
	}

// 	Name, Coordinates, Room_flag, id_informaion, time_stamp, position
//	These information shouldn't be changed anymore.	
	my_file= replace_string(my_file,"SHORT_TITLE",s_title);
	my_file= replace_string(my_file,"LONG_TITLE",l_title);
	my_file= replace_string(my_file,"#define X_COOR 0",
		sprintf("#define X_COOR %d",
		new_x((int)environment(me)->query("coor/x"),dir)));	
    my_file= replace_string(my_file,"#define Y_COOR 0",
        sprintf("#define Y_COOR %d",
        new_y((int)environment(me)->query("coor/y"),dir)));
    my_file= replace_string(my_file,"#define Z_COOR 0",
        sprintf("#define Z_COOR %d",
        new_z((int)environment(me)->query("coor/z"),dir)));
	my_file= replace_string(my_file,"#define R_FLAG 0",
        sprintf("#define R_FLAG %d",flag));
	
	if(me->query("family/family_name"))
		my_file= replace_string(my_file,"bigwiz7001",
			me->query("family/family_name"));
    
    my_file= replace_string(my_file,"#define OWNER \"mingyue\"",
        	sprintf("#define OWNER \"%s\"",me->query("id")));
	
    my_file= replace_string(my_file,"bigtie7001",
        me->query("id"));
    my_file= replace_string(my_file,"anniestamp",
        (me->query("created_room")+1)+"");
        my_file= replace_string(my_file,"mystamp",
        time()+"");
            
    my_file= replace_string(my_file,"#define CONSTRUCT_TREE 0",
        sprintf("#define CONSTRUCT_TREE %d",environment(me)->query("tree")+1));
	
//	Detailed ROOM INFORMATION.	
/*	W=1/0 & Free_space decide the whole room charges. 
	Other parameters are calculated from these 2 values.
	The calculation is done first in /p/residence/ann_residence 
	
	Free_Space: This could be upgraded later on
	Total_Gold: The total (buyout) gold cost
	Total_score The total (buyout) score cost
	BASIC_tax:  Weekly gold charge
	Basic_score_tax:  Weekly score charge
*/	
    my_file= replace_string(my_file,"#define FREE_SPACE 4",
        sprintf("#define FREE_SPACE %d",spa));
    
	if (w == 1) {
		my_file= replace_string(my_file,"#define BASIC_TAX 0",
        	sprintf("#define BASIC_TAX %d",-1));	// -1 means it's clear
		my_file = replace_string(my_file,"#define TOTAL_GOLD 0",
			sprintf("#define TOTAL_GOLD %d",gc));
		my_file = replace_string(my_file,"#define TOTAL_SCORE 0",
			sprintf("#define TOTAL_SCORE %d",sc));
	} else {
		my_file= replace_string(my_file,"#define BASIC_TAX 0",
        	sprintf("#define BASIC_TAX %d",gc*14));	// gold*14*100/100(weeks) = (gold*14) (silver/week)
		my_file = replace_string(my_file,"#define TOTAL_GOLD 0",
			sprintf("#define TOTAL_GOLD %d",gc*15));					// Total gold
		my_file = replace_string(my_file,"#define TOTAL_SCORE 0",		// Total Score
			sprintf("#define TOTAL_SCORE %d",sc+spa*100));
	}	
		
	my_file= replace_string(my_file,"#define BASIC_SCORE_TAX 0",
        sprintf("#define BASIC_SCORE_TAX %d",spa*100));		// actually this is the total score needed		
	
// now we need to write out this file!
// do NOT change this one!
	if (!write_file("/p/residence/userroom/"+name+".o",my_file,1)){
		tell_object(me,"房屋创建失败，请立即通知巫师，失败代码Room_001\n");
		return;
	}
	
#ifdef	ENCRYPTED_WRITE	
	if (!write_file2("/p/residence/userroom/"+name+".c",my_file,1)){
		tell_object(me,"房屋创建失败，请立即通知巫师，失败代码Room_002\n");
		return;
	}
#endif

#ifdef  NONENCRYPTED_WRITE	
	if (!write_file("/p/residence/userroom/"+name+".c",my_file,1)){
		tell_object(me,"房屋创建失败，请立即通知巫师，失败代码Room_002\n");
		return;
	}
#endif
	
	env = load_object("/p/residence/userroom/"+name+".c");
	
	me->add("created_room",1);

	//	Not used, but a mark remains.
	if (!environment(me)->query("tree"))
		me->add("created_mainroom",1);
	
    gold->add_amount(-gc);
	me->add("score",-sc);
	
	env->set("already_pay",gc*100);
	env->set("already_spay",sc);
	
	if (w == 1){
		log_file("annie_log_buildroom", 
			sprintf("Payoff: [%s] %s(%s)的自建房屋%s已经付清款项，档名为%s。\n",
			ctime(time()), 
			me->query("name"),
			me->query("id"),
			env->query("short"),
			base_name(env)));
		env->set("basic_tax",-1);
	}
	
	env->save();
	me->save();
	write("房屋创建成功！！创建人资料存储成功！！\n");

}

int new_x(int x, string dir)
{
	switch (dir) {
	case "east" :
        case "eastup" :
        case "eastdown" :
        case "northeast" :
        case "southeast" :	return x+10;
	case "west" :
        case "westdown" :
        case "westup" :
        case "northwest" :
        case "southwest" :	return x-10;

	default: return x;
	}

} 
int new_y(int y, string dir)
{
        switch (dir) {
		case "north" :
        case "northup" :
        case "northdown" :
        case "northeast" :
        case "northwest" : return y+10;
        case "south" :
        case "southup" :
        case "southdown" :
        case "southeast" :
        case "southwest" : return y-10;

        default: return y;
        }

}
int new_z(int z, string dir)
{
        switch (dir) {
		case "up" :
        case "northup" :
        case "southup" :
        case "eastup" :
        case "westup" : return z+10;
        case "down" :
        case "eastdown" :
        case "westdown" :
        case "northdown" :
        case "southdown" : return z-10;

        default: return z;
        }

}

void reclaim_room(object room)
{
	object roomx;
	mapping exits,exits2;
	string *exs,*exs2;
	string c_name,o_name;
	object owner,owner2;
	int i,j;
	string this_file;
	int tree;
	string a1,a2,dir;
	
	seteuid(getuid());
	exits = room->query("exits");
	tree=room->query("tree");
	if (!tree)
		return;		// no tree room? 

	exs=keys(exits);
	for (i=0; i<sizeof(exs);i++ )
	{
		roomx = find_object(exits[exs[i]]);
		if (!roomx)
			roomx = load_object(exits[exs[i]]);
		if (!roomx)
			continue;	// 屋子不明丢失。
		if (roomx->query("tree") == tree-1)
		// 连接树的上一层
		{
			// 修改该屋子连接
			c_name = base_name(roomx)+".c";
			o_name = base_name(roomx)+".o";
			
			exits2=roomx->query("exits");
			exs2=keys(exits2);

			a2 = base_name(room);
			// /p/residence/userroom/mingyue1100161390
			for (j=0;j<sizeof(exs2); j++)
				if (exits2[exs2[j]] == a2)
					dir=exs2[j];

			if (tree == 1)	// 最外层
				a2=replace_string(a2,"/p/residence/","");
			else
				a2=replace_string(a2,"/p/residence/userroom/","");

			// userroom/mingyue1100161390

			a2 = "\""+dir+"\" : __DIR__\""+a2+"\",\n";
			roomx->delete("exits/"+dir);
			CHANNEL_D->do_channel( this_object(), "announce",sprintf(HIG"：因长期欠款，系统收回"+roomx->query("short")+"房间"+a2+""NOR));

			// roomx->save(); // 用于tree>1

		//	this_file = read_file(c_name);
			this_file = read_file(o_name);
					
			this_file = replace_string(this_file,a2,"");	
			
			write_file(o_name,this_file,1);

#ifdef	ENCRYPTED_WRITE	
			write_file2(c_name,this_file,1);
#endif

#ifdef	NONENCRYPTED_WRITE
			write_file(c_name,this_file,1);
#endif
			
		}
	}

	tell_room(room,HIR"此房间因长期拖欠租金，已被系统收回，请速离此处。\n"NOR);
	a1 = base_name(room);
	a2 = base_name(room);
	a2=replace_string(a2,"/p/residence/userroom/","/p/residence/userroom/backup/");
	rename(a1+".c",a2+".c");
	rename(a1+".o",a2+".o");


	// load user, add "created_room",-1;

	i=0;
	owner = find_player(room->query("owner"));
	if (!owner)
	{
		owner2=FINGER_D->acquire_login_ob(room->query("owner"));
		if (!owner2)
                return ;	// owner purged or suicided.
		owner=LOGIN_D->make_body(owner2);
		if (!owner)
                return ;	// owner purged or suicided.
		if (!owner->restore())
                return ;	// owner purged or suicided.
		i=1;
	}
	if (tree == 1)
//	owner->add("created_mainroom",-1);
	owner->add("created_room",-1);
	owner->save();
	log_file("annie_log_buildroom", sprintf("Upkeep: [%s] %s(%s)的自建房屋%s被销毁了，档名为%s。\n",
		ctime(time()), owner->query("name"),owner->query("id"),room->query("short"),a1));
	if (i)
	{
		destruct(owner);
		destruct(owner2);
	}
	return;
}

//	This is for wizard to destroy player rooms
void destroy_room(){
	
	object me = this_player();
	string file;
	if (!wizardp(me) || wiz_level(me) < 4 ){
		tell_object(me,"此命令唯有Ａｒｃｈ才能使用。\n");
		return;
	}
	
	tell_object(me,"base room is "+ base_name(environment(me))+"  ");
	if (file_size(base_name(environment(me))+".c")== -1) {
		tell_object(me,"该房间已经不存在了。\n");
		return;
	}
	
	reclaim_room(environment(me));		
	return;	
}

int touch_file(string name)
{
	if(write_file(name," ",1))
		return 1;
	else return 0;
}

void process()
{
	string dir;
	mixed *file;
	int i, t;
	object room;
	dir = "/p/residence/userroom/";
	file = get_dir(dir, -1);
	
    CHANNEL_D->do_channel( this_object(), "announce",sprintf(HIG"正在清理居民住区．．．"NOR));

	seteuid(getuid());

	i = sizeof(file);
	while (i--)
	{
		if (strsrch(file[i][0],".c")!=-1 )
		{
			// read .c files.
			room = find_object(dir+file[i][0]);
			if (!room)
				room = load_object(dir+file[i][0]);
			room->init();
			write(room->query("short"));
			
			CHANNEL_D->do_sys_channel("sys",sprintf("time is %d, room pay time is %d, difference is %d",
						time(), room->pay_time(), (time()-room->pay_time())/DAY/7));
			if(room->query("room_last_enter")  && (time()- room->query("room_last_enter")) / 86400 >= 30  ){
			reclaim_room(room);
			}	
					
						
			if (time() > room->pay_time() + DAY*7 && room->query("basic_tax") != -1)
			{
					
				room->add("expired",1);				// 使用相对值，保证只有系统运行时才计算房屋租金
				
				CHANNEL_D->do_sys_channel("sys", "room expiration is "+ room->query("expired")+"\n");
				room->save();
				if (room->query("expired") > 356)	// 未缴后一年未补缴upkeep则收回。
				{
						reclaim_room(room);		
				}
			}
		}
	}

    CHANNEL_D->do_channel( this_object(), "announce",sprintf(HIR"．．．清理完成。"NOR));
	call_out("process",DAY);
	return;
}

/*
// 该过程耗费系统资源，在启动后由WIZ主动执行，检查系统屋子状况并作相应修改

void system_process()
{
	string dir;
	mixed *file;
	int i, t, j;
	object room;
	dir = "/p/residence/userroom/";
	file = get_dir(dir, -1);
	
  CHANNEL_D->do_channel( this_object(), "announce",sprintf(HIG"正在对所有住房进行半年一次的整理．．．"NOR));

	seteuid(getuid());

	i = sizeof(file);
	while (i--)
	{
		if (strsrch(file[i][0],".c")!=-1 )
		{
			// read .c files.
			room = find_object(dir+file[i][0]);
			if (!room)
				room = load_object(dir+file[i][0]);
			room->init();
//			write(room->query("short"));
			
//			CHANNEL_D->do_sys_channel("sys",sprintf("time is %d, room pay time is %d, difference is %d",
//						time(), room->pay_time(), (time()-room->pay_time())/DAY/7));
			
			
				// load user, add "created_room",-1;

		j=0;
		owner = find_player(room->query("owner"));
		if (!owner)
		{
			owner2=FINGER_D->acquire_login_ob(room->query("owner"));
			if (!owner2)
	                ;	// owner purged or suicided.
			owner=LOGIN_D->make_body(owner2);
			if (!owner)
	                return ;	// owner purged or suicided.
			if (!owner->restore())
	                return ;	// owner purged or suicided.
			j=1;
		}
		
		delta = time()- owner->
		
		if (j)
		{
			destruct(owner);
			destruct(owner2);
		}
						
reclaim_room(object room)

		}
	}

    CHANNEL_D->do_channel( this_object(), "announce",sprintf(HIR"．．．清理完成。"NOR));
	call_out("process",DAY);
	return;
}
*/

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
