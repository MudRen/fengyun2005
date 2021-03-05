// PRIVATE MAZE GENERATOR


#pragma optimize

#define UP		32
#define D		16
#define N		8
#define S		4
#define W		2
#define E		1
#define ALL		63

#define MAX_LONG	100

#define VALID_LEAVES 3

inherit F_CLEAN_UP;
#include <ansi.h>;

class coordinate{ int x; int y; int z;}
class coordinate *newpath = ({}),/*待处理队列*/
	enter,/* 入口坐标 */
	leave;/* 出口坐标 */

protected string *valid_dirs = ({ "south","north","west","east","up","down",});
protected mapping reverse_dir = ([
"north" : "south",
"south" : "north",
"west"  : "east",
"east"  : "west",
"down"	: "up",
"up"	: "down",
]);


// 全迷宫出口阵列.
protected mixed *all;

/***************** 迷宫的一些预设特性：*****************/
protected int l;				// 迷宫的东西向单边长
protected int m;				// 迷宫的南北向单边长
protected int h;				// 迷宫的高低向单边长
protected int s;				// 迷宫每格的坐标差，ｄｅｆａｕｌｔ＝１０
protected string *inherit_rooms = ({});	// 迷宫允许继承的档案名称
protected string entry_dir;		// 迷宫入口方向
protected string link_entry_dir;		// 迷宫入口与区域的连接方向
protected string link_entry_room;		// 迷宫入口所连接区域档案的文件名
protected int link_entry_room_x;		// 迷宫入口的x坐标
protected int link_entry_room_y;		// 迷宫入口的y坐标
protected int link_entry_room_z;		// 迷宫入口的z坐标
protected string link_exit_dir;		// 迷宫出口与区域的连接方向
protected string link_exit_room;		// 迷宫出口所连接区域档案的文件名
protected string entry_short;		// 迷宫入口的短描述
protected string entry_desc;		// 迷宫入口的长描述
protected string exit_short;		// 迷宫出口的短描述
protected string exit_desc;		// 迷宫出口的长描述
protected string *maze_room_desc	= ({});	// 迷宫房间的长描述
protected string maze_room_short;		// 迷宫房间的短描述
protected int is_outdoors = 0;		// 迷宫房间是否为户外
protected int refresh_delay = 300;  	//迷宫重建时间, default is 0 means no recreation
protected int private_flag = 1;				// Privite Maze? // annie. 09.2003
protected string owner;				// protected maze owner
protected object mark_ob;				// who got the "maze" mark?
/******************* ---- END ---- *********************/

// 建立标记.
protected int maze_built = 0;

// 重置全域变量.
protected void refresh_vars();

// 建立迷宫
protected void create_maze();

// 选择随机出口.
protected int random_out(int x,int y,int z,int n);

//设置迷宫单位长
protected void set_maze_spacing(int space);

nomask object query_maze_room(string str);

// 处理连接.
protected void link_to_north(int x,int y,int z);
protected void link_to_south(int x,int y,int z);
protected void link_to_west(int x,int y,int z);
protected void link_to_east(int x,int y,int z);
protected void link_to_up(int x,int y,int z);
protected void link_to_down(int x,int y,int z);

// 绘制已建成迷宫的地图.
protected void paint_vrm_map();

// 检查某个房间里是否有 players
protected int player_in(object m_room);

// 去除迷宫 --- 所有players将去VOID
protected void remove();

// 重新创建迷宫
protected void refresh_maze();

int remove_all_players(object maze_room,object exile_room,string remove_msg);


// 调试信息。
protected string mroom_fname(int x,int y,int z)
	{ return sprintf("%s/%s/%d/%d/%d",base_name(this_object()),owner,x,y,z);}
	
int query_maze_length(){
	return l;
}	

int query_maze_height(){
	return m;
}

int query_maze_altitude(){
	return h;
}

// 重置全域变量.
protected void refresh_vars() 
{
	newpath = ({});
	all = 0;
}

// 对一些必设参数的合法性检查
protected int check_vars()
{
	int i,n;

	if( (l < 2) || l > MAX_LONG )
		return 0;

	if( (m < 2) || m > MAX_LONG )
		return 0;
		
	if( h > MAX_LONG )
		return 0;
		
	inherit_rooms -=({0});
	if( !n = sizeof(inherit_rooms) )
		return 0;

	for(i=0;i<n;i++)
		if(!stringp(inherit_rooms[i]) || (inherit_rooms[i] == ""))
			return 0;

	if(!stringp(entry_dir) || (member_array(entry_dir,valid_dirs) == -1) )
		return 0;

	if(!stringp(link_entry_room) || (link_entry_room == ""))
		return 0;

	if(!stringp(link_exit_room) || (link_exit_room == ""))
		return 0;

	if(!stringp(entry_short) || (entry_short == ""))
		return 0;

	if(!stringp(exit_short) || (exit_short == ""))
		return 0;

	if(!stringp(entry_desc) || (entry_desc == ""))
		return 0;

	if(!stringp(exit_desc) || (exit_desc == ""))
		return 0;

	maze_room_desc -=({0});
	if( !n = sizeof(maze_room_desc) )
		return 0;

	for(i=0;i<n;i++)
		if(!stringp(maze_room_desc[i]) || (maze_room_desc[i] == ""))
			return 0;

	if(!stringp(maze_room_short) || (maze_room_short == ""))
		return 0;

	return 1;
}


protected int random_out(int x,int y,int z,int n) // 选择随机出口函数.
{
	int *outs = ({}), retn = 0;
	class coordinate temp;

	// The west room is (x-1,y)
	if( n&W
	&& ((x-1) >= 0)
	&& !all[x-1][y][z] )
	{
		temp = new(class coordinate);
		temp->x = x-1;
		temp->y = y;
		temp->z = z;

		// 西面的房间不在待处理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ W });
	}

	// The east room is (x+1,y)
	if( n&E
	&& ((x+1) < l)
	&& !all[x+1][y][z] )
	{
		temp = new(class coordinate);
		temp->x = x+1;
		temp->y = y;
		temp->z = z;

		// 东面的房间不在待处理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ E });
	}

	// The south room is (x,y-1)
	if( n&S
	&& ((y-1) >= 0)
	&& !all[x][y-1][z] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y-1;
		temp->z = z;

		// 南面的房间不在待处理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ S });
	}

	// The north room is (x,y+1)
	if( n&N
	&& ((y+1) < m)
	&& !all[x][y+1][z] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y+1;
		temp->z = z;

		// 北面的房间不在待处理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ N });
	}

	// The up room is (x,y,z+1)
	if( n&UP
	&& ((z+1) < h)
	&& !all[x][y][z+1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y;
		temp->z = z+1;

		// 上面的房间不在待处理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ UP });
	}

	// The down room is (x,y,z-1)
	if( n&D
	&& ((z-1) >= 0)
	&& !all[x][y][z-1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y;
		temp->z = z-1;

		// 下面的房间不在待处理列表 newpath 中.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ D });
	}

#ifdef VALID_LEAVES
	// 如果有三个出口,随机关闭一个.	// ann' marked
//	if(sizeof(outs) >= 3)
	while(sizeof(outs) >= VALID_LEAVES)
		outs -= ({ outs[random(sizeof(outs))] });
#endif

	for(int i=0;i<sizeof(outs);i++)
		retn |= outs[i];

	return retn;
}

protected void create_maze()
{
	int i,j;
	class coordinate *valid_leaves=({}),temp;
	object who;

	refresh_vars(); // 重置全域变量.
	if( !check_vars() )   // 对一些预设变量进行检查。
		return;

		// Here we set the owner and regain something. ;Annie 08-05

		who=find_player(owner);


	l=4;
	m=4;
	h=2;



	// 1.确定迷宫单边长.
	all = allocate(l);
	for(i=0;i<l;i++)
		all[i] = allocate(m);	// 建立数组.
	for(i=0;i<l;i++)
		for(j=0;j<m;j++)
			all[i][j] = allocate(h);	// 建立数组.
	
	CHANNEL_D->do_sys_channel("sys",sprintf("Start building maze"));
	CHANNEL_D->do_sys_channel("sys",sprintf("Start building maze in %s/%s",base_name(this_object()),owner));

	
	
	enter = new(class coordinate);

	switch (entry_dir)
	{
		case "south":
			// enter 入口坐标.
			enter->x = to_int(l/2); // 取中迷宫比较平衡。
			enter->y = 0;
			enter->z = 0;
			all[enter->x][enter->y][enter->z] |= S;
			break;
		case "north":
			enter->x = to_int(l/2);
			enter->y = m-1;
			enter->z = 0;
			all[enter->x][enter->y][enter->z] |= N;
			break;
		case "west":
			enter->y = to_int(m/2);
			enter->x = 0;
			enter->z = 0;
			all[enter->x][enter->y][enter->z] |= W;
			break;
		case "east":
			enter->y = to_int(m/2);
			enter->x = l-1;
			enter->z = 0;
			all[enter->x][enter->y][enter->z] |= E;
			break;
		case "up":
			enter->z = h-1;
			enter->y = to_int(m/2);
			enter->x = to_int(l/2);
			all[enter->x][enter->y][enter->z] |= UP;
			break;
		case "down":
			enter->z = 0;
			enter->y = to_int(m/2);
			enter->x = to_int(l/2);
			all[enter->x][enter->y][enter->z] |= D;
			break;
	}

	// 存入待处理队列.
	newpath += ({ enter });

	// 进入主循环.
	do
	{
		int x,y,z,out,numb;

		// 进行一些监测与初始化.
		if( !(numb=sizeof(newpath)) )
			continue;
		numb = random(numb);
		reset_eval_cost();
		x = newpath[numb]->x;
		y = newpath[numb]->y;
		z = newpath[numb]->z;

		// 如果有三个可能的出口随机关闭一个出口:
		out = ALL^(all[x][y][z]);
		out = random_out(x,y,z,out);

		if(!out) // 没有可能的出口了.
		{
			newpath -= ({ newpath[numb] });
			continue;
		}

		// 处理连接.
		if(out&W) link_to_west(x,y,z);
		if(out&E) link_to_east(x,y,z);
		if(out&N) link_to_north(x,y,z);
		if(out&S) link_to_south(x,y,z);
		if(out&UP) link_to_up(x,y,z);
		if(out&D) link_to_down(x,y,z);

		// 当前房间处理完毕.
		newpath -= ({ newpath[numb] });
	}
	while (sizeof(newpath));

	switch (entry_dir)
	{
		case "west":
			for(i=0;i<m;i++)
				for(j=0;j<h;j++)
					if(all[l-1][i][j])
					{
						temp = new(class coordinate);
						temp->x = l-1;
						temp->y = i;
						temp->z = j;
						valid_leaves += ({temp});
					}
			break;
		case "east":
			for(i=0;i<m;i++)
				for(j=0;j<h;j++)
					if(all[0][i][j])
					{
						temp = new(class coordinate);
						temp->x = 0;
						temp->y = i;
						temp->z = j;
						valid_leaves += ({temp});
					}
			break;
		case "south":
			for(i=0;i<l;i++)
				for(j=0;j<h;j++)
					if(all[i][m-1][j])
					{
						temp = new(class coordinate);
						temp->x = i;
						temp->y = m-1;
						temp->z = j;
						valid_leaves += ({temp});
					}
			break;
		case "north":
			for(i=0;i<l;i++)
				for(j=0;j<h;j++)
					if(all[i][0][j])
					{
						temp = new(class coordinate);
						temp->x = i;
						temp->y = 0;
						temp->z = j;
						valid_leaves += ({temp});
					}
			break;
		case "up":
			for(i=0;i<l;i++)
				for(j=0;j<m;j++)
					if(all[i][j][0])
					{
						temp = new(class coordinate);
						temp->x = i;
						temp->y = j;
						temp->z = 0;
						valid_leaves += ({temp});
					}
			break;
		case "down":
			for(i=0;i<l;i++)
				for(j=0;j<m;j++)
					if(all[i][j][h-1])
					{
						temp = new(class coordinate);
						temp->x = i;
						temp->y = j;
						temp->z = h-1;
						valid_leaves += ({temp});
					}
			break;
	}

	if( !(i=sizeof(valid_leaves)) ) // 没有出口 须重新建立
	{
		call_other(this_object(),"create_maze");
		return;
	}

	if(i == 1)
		leave = valid_leaves[0];
	else
		leave = valid_leaves[random(i)]; // 随机选一个.

	switch (entry_dir)
	{
		case "south":
			all[leave->x][leave->y][leave->z] |= N;
			break;
		case "north":
			all[leave->x][leave->y][leave->z] |= S;
			break;
		case "west":
			all[leave->x][leave->y][leave->z] |= E;
			break;
		case "east":
			all[leave->x][leave->y][leave->z] |= W;
			break;
		case "up":
			all[leave->x][leave->y][leave->z] |= D;
			break;
		case "down":
			all[leave->x][leave->y][leave->z] |= UP;
			break;
	}

	// 迷宫创建完毕。
	maze_built = 1;
	
	if (refresh_delay > 0  )
	{
		EVENT_D->add_event(time()+refresh_delay,this_object(),(:refresh_maze:));
	}
	
	// 绘制完成的迷宫地图。
	// 地图文件为同目录下同名的'.map' 文件，
	// 绘制地图也许可利于区域巫师的工作。
	// 如需要可开放物件对于本目录的'写'。
		    paint_vrm_map();	// ann' marked
}




protected void link_to_west(int x,int y,int z)	// The west room is (x-1,y)
{
	class coordinate temp;
	// can't link. 当前房间已经是最西面的房间了.
	if( (x-1) < 0 )
		return;

	temp = new(class coordinate);
	temp->x = x-1;
	temp->y = y;
	temp->z = z;

	// 西面的房间已经于 path 中,或者 已在待处理列表 newpath 中.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= W;
	all[temp->x][temp->y][temp->z] |= E;
	newpath += ({temp});
}

protected void link_to_east(int x,int y,int z)	// The east room is (x+1,y)
{
	class coordinate temp;
	// can't link. 当前房间已经是最东面的房间了.
	if( (x+1) >= l )
		return;

	temp = new(class coordinate);
	temp->x = x+1;
	temp->y = y;
	temp->z = z;

	// 东面的房间已经于 path 中,或者 已在待处理列表 newpath 中.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= E;
	all[temp->x][temp->y][temp->z] |= W;
	newpath += ({temp});
}

protected void link_to_south(int x,int y,int z)	// The south room is (x,y-1)
{
	class coordinate temp;
	// can't link. 当前房间已经是最南端的房间了.
	if( (y-1) <0 )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y-1;
	temp->z = z;

	// 南端的房间已经于 path 中,或者 已在待处理列表 newpath 中.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= S;
	all[temp->x][temp->y][temp->z] |= N;
	newpath += ({temp});
}

protected void link_to_north(int x,int y,int z)	// The north room is (x,y+1)
{
	class coordinate temp;
	// can't link. 当前房间已经是最北端的房间了.
	if( (y+1) >= m )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y+1;
	temp->z = z;

	// 北端的房间已经于 path 中,或者 已在待处理列表 newpath 中.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= N;
	all[temp->x][temp->y][temp->z] |= S;
	newpath += ({temp});
}

protected void link_to_up(int x,int y,int z)	// The up room is (x,y,z+1)
{
	class coordinate temp;
	// can't link. 当前房间已经是最上层的房间了.
	if( (z+1) >= h )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y;
	temp->z = z+1;

	// 北端的房间已经于 path 中,或者 已在待处理列表 newpath 中.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= UP;
	all[temp->x][temp->y][temp->z] |= D;
	newpath += ({temp});
}

protected void link_to_down(int x,int y,int z)	// The up room is (x,y,z-1)
{
	class coordinate temp;
	// can't link. 当前房间已经是最下层的房间了.
	if( (z-1) < 0)
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y;
	temp->z = z-1;

	// 北端的房间已经于 path 中,或者 已在待处理列表 newpath 中.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= D;
	all[temp->x][temp->y][temp->z] |= UP;
	newpath += ({temp});
}

// 绘制已建成迷宫的地图.
// ann' marked 暂时不叫此函式。
protected void paint_vrm_map()
{
	string hor = "─" ,ver = "│  ",room = "◎",sroom = "●",ld = "▽", lu = "△", lb = "◇";
	int x,y,z;
	string output = "",map_file;
	object e;

	for (z = (h-1); z>=0; z--)
	{
		for(y=(m-1);y>=0;y--)
		{
			reset_eval_cost();

			output += sprintf("y=%-3d: ",y);
			for(x=0;x<l;x++)
			{
				if ( (x==enter->x && y==enter->y && z == enter->z)
					|| (x==leave->x && y==leave->y && z == leave->z) )
				{
					output += sroom;
				}
				else if ((all[x][y][z])&UP && (all[x][y][z])&D)
				{
					output += lb;
				}
				else if ((all[x][y][z])&UP)
				{
					output += lu;
				}
				else if ((all[x][y][z])&D)
				{
					output += ld;
				}
				else
				{
					output += room;
				}

				if( (all[x][y][z])&E ) // have east
					output += hor;
				else
					output += "  ";



			}

			output += "\n";
			output += "       ";
			for(x=0;x<l;x++)
			{
				if( (all[x][y][z])&S ) // have south
					output += ver;
				else
				output += "    ";
			}
			output += "\n";
		}
		output += "\nFloor "+z+"\n ------------------------------\n";
	}

	map_file = sprintf( "%s_%s.map",base_name(this_object()),owner);
	write_file(map_file,output,1);
}

nomask int clean_up()
{
	string fname;
	int x,y,z;
	object *maze_objs = ({}),link_room;

	if(!maze_built)
	{
		destruct(this_object());
		return 0;
	}

	fname = base_name(this_object());

	if( objectp(link_room = find_object(sprintf("%s/%s/entry",fname,owner))) )
	{
		link_room->clean_up();
		if( objectp(link_room) )
			return 1;
	}

	if( objectp(link_room = find_object(sprintf("%s/%s/exit",fname,owner))) )
	{
		link_room->clean_up();
		if( objectp(link_room) )
			return 1;
	}

	for(x=0;x<l;x++)
		for(y=0;y<m;y++)
			for(z=0;z<h;z++)
				if(objectp(find_object(sprintf("%s/%s/%d/%d/%d",fname,owner,x,y,z))))
					maze_objs += ({find_object(sprintf("%s/%s/%d/%d/%d",fname,owner,x,y,z))});

	maze_objs->clean_up();
	maze_objs -= ({0});

	if(sizeof(maze_objs))
		return 1;
	else
	{
		destruct(this_object());
		return 0;
	}
}

// 巫师可以 update 区域迷宫主物件强制更新迷宫，
// 但此时迷宫中的玩家就要去 VOID 了。

void remove()
{
	string fname = base_name(this_object());
	object m_room;
	int x,y,z;
	
	for(x=0;x<l;x++)
		for(y=0;y<m;y++)
			for(z=0;z<h;z++)
				if(objectp(m_room = find_object(sprintf("%s/%s/%d/%d/%d",fname,owner,x,y,z))))
					destruct(m_room);
	if(objectp(m_room = find_object(sprintf("%s/%s/entry",fname,owner))))
		destruct(m_room);
	
//	log_file("debug.log", sprintf("%s/%s/exit",fname,owner));

	if(objectp(m_room= find_object(sprintf("%s/%s/exit",fname,owner))))
		destruct(m_room);
}

void refresh_maze()
{
/*
	if (this_object()->has_player())
	{
		//has players in maze re-try 10 mins later;
		CHANNEL_D->do_sys_channel("sys","maze has players in, will retry 10 mins later");
		EVENT_D->add_event(time()+600,this_object(),(: refresh_maze :));
		return;
	}
*/
	remove_all_players(this_object(),this_object(),"郭大妈高喊道：出来，出来了诶！封窖的时候到了！\n你现在可以向郭大妈回报结果(end)了……\n");
	remove();
	CHANNEL_D->do_sys_channel("sys",owner+"' maze destructed");
	destruct(this_object());
	return;
}

//	检查迷宫中是否有玩家
int has_player()
{
	string fname = base_name(this_object());
	object m_room;
	int x,y,z;

	for(x=0;x<l;x++)
	{
		for(y=0;y<m;y++)
		{
			for(z=0;z<h;z++)
			{
				if(objectp(m_room = find_object(sprintf("%s/%s/%d/%d/%d",fname,owner,x,y,z))))
					if (player_in(m_room))
						return 1;
			}
		}
	}
				
	if(objectp(m_room = find_object(sprintf("%s/%s/entry",fname,owner))))
		if (player_in(m_room))
			return 1;

	if(objectp(m_room = find_object(sprintf("%s/%s/exit",fname,owner))))
		if (player_in(m_room))
			return 1;
	return 0;
}

//	检查某个房间里是否有玩家。

int player_in(object m_room)
{
	object *inv;
	inv = all_inventory(m_room);
	for (int i = 0;i < sizeof(inv) ; i++)
		//if player in the room return
		if (userp(inv[i]))
			return 1;

	return 0;
}


//	把所有玩家从迷宫里搬走。
int remove_all_players(object maze_room,object exile_room,string remove_msg){
	
	string fname = base_name(maze_room);
	object m_room,*inv;
	string c;
	int x,y,z,k,num,length,height,altitude;

	object wer;
	wer = find_object("/d/taoyuan/guojia1");
	if (!wer)
		wer = load_object("/d/taoyuan/guojia1");

	length=maze_room->query_maze_length();
	height=maze_room->query_maze_height();
	altitude=maze_room->query_maze_altitude();
	
	
	for(x=0;x<length;x++)
	{
		for(y=0;y<height;y++)
		{
			for(z=0;z<altitude;z++)
			{
				c=sprintf("%s/%s/%d/%d/%d",fname,owner,x,y,z);
				if(objectp(m_room = find_object(c))) {


					tell_room(m_room,remove_msg);
					inv=all_inventory(m_room);
					num=sizeof(inv);
					while(num--) {
						if (userp(inv[num])) 
							inv[num]->move(wer);	
						if (inv[num]->query("possessed"))
							if (userp(inv[num]->query("possessed")))
								inv[num]->move(wer);	
					}	
				}	
			}
		}
	}
				
	if(objectp(m_room = find_object(sprintf("%s/%s/entry",fname,owner)))) {
		tell_room(m_room,remove_msg);
		inv=all_inventory(m_room);
		num=sizeof(inv);
		while(num--) {
						if (userp(inv[num])) 
							inv[num]->move(wer);	
						if (inv[num]->query("possessed"))
							if (userp(inv[num]->query("possessed")))
								inv[num]->move(wer);	
		}
	}
	
	if(objectp(m_room = find_object(sprintf("%s/%s/exit",fname,owner))))	{
		tell_room(m_room,remove_msg);
		inv=all_inventory(m_room);
		num=sizeof(inv);
		while(num--) {
						if (userp(inv[num])) 
							inv[num]->move(wer);	
						if (inv[num]->query("possessed"))
							if (userp(inv[num]->query("possessed")))
								inv[num]->move(wer);	
		}
	}
	
}



/**** 以下是预设迷宫参数的接口函数 ****/
// 迷宫的单边长
void set_maze_long(int mlong, int mheight,int maltitude)
{
	if(!intp(mlong) || !intp(mheight))
		return;

	if (!intp(maltitude))
		maltitude = 0;

	// 最小为 5，再小了没什么意义。
	if( (mlong < 2) || mlong > MAX_LONG 
		|| mheight<2 || mheight > MAX_LONG || maltitude > MAX_LONG)
		return;

	l = mlong;
	m = mheight;
	h = maltitude;
}

// 迷宫房间所继承的物件的档案名称。
void set_inherit_room( mixed rooms )
{
	if(stringp(rooms))
	{
		// 此档案是否存在
		if(file_size(sprintf("%s.c",rooms)) > 0)
			inherit_rooms = ({ rooms });
		return;
	}

	else if(arrayp(rooms))
	{
		foreach(string f in rooms)
		{
			if(!stringp(f) || f == "")
				return;
			if(file_size(sprintf("%s.c",f)) <= 0)
				return;
		}
		inherit_rooms = rooms;
		return;
	}

	return;
}

// 入口方向(出口在对面)
void set_entry_dir(string dir)
{
	if(!stringp(dir))
		return;
	
	private_flag=1;

	// 入口方向的合法性检查.
	if(member_array(dir,valid_dirs) == -1)
		return;

	entry_dir = dir;
}

//入口与区域的连接方向
void set_link_entry_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_entry_dir = dir;
}

// 迷宫入口所连接区域档案的文件名
void set_link_entry_room(string lroom)
{
	if(!stringp(lroom) || lroom == "")
		return;

	if(file_size(sprintf("%s.c",lroom)) <= 0)
		return;

	link_entry_room = lroom;
}

// 迷宫入口房间的坐标，我们无法用简单的方法把迷宫坐标安排在
// 进口/出口内（这个需要得到迷宫与区域的关系）
// 所以我们认为迷宫是进口区域延伸的一部分，当走出迷宫出口时，跳跃进入下一个区域。
// 缺点是，一个大迷宫的坐标可能与真实区域重叠，这个就要设计者自己留意了，
// 比如说，不要把100x100的迷宫安排在 (1,1)和 (10,10)之间。。。。自己算一下吧

void set_link_entry_room_x(int x)
{
	if(!intp(x)) link_entry_room_x=0;
		else	link_entry_room_x = x;
}


void set_link_entry_room_y(int y)
{
	if(!intp(y)) link_entry_room_y=0;
		else	link_entry_room_y = y;
}


void set_link_entry_room_z(int z)
{
	if(!intp(z)) link_entry_room_z=0;
		else	link_entry_room_z = z;
}


//设置迷宫单位长
void set_maze_spacing(int space) {
	if (!intp(space)) s=10;
		else s=space;
}


//出口与区域的连接方向
void set_link_exit_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_exit_dir = dir;
}

// 迷宫出口所连接区域档案的文件名
void set_link_exit_room(string lroom)
{
	if(!stringp(lroom) || lroom == "")
		return;

	if(file_size(sprintf("%s.c",lroom)) <= 0)
		return;

	link_exit_room = lroom;
}

// 迷宫入口的短描述
void set_entry_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	entry_short = desc;
}

// 迷宫入口的长描述
void set_entry_desc(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	entry_desc = desc;
}

// 迷宫出口的短描述
void set_exit_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	exit_short = desc;
}

// 迷宫出口的长描述
void set_exit_desc(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	exit_desc = desc;
}

//迷宫房间的短描述
void set_maze_room_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	maze_room_short = desc;
}

//迷宫房间的描述，如果有多条描述，制造每个房
//间的时候会从中随机选择一个。
void set_maze_room_desc(mixed desces)
{
	if(stringp(desces))
	{
		maze_room_desc = ({ desces });
		return;
	}

	if(arrayp(desces))
	{
		foreach(string desc in desces)
			if(!stringp(desc))
				return;
		maze_room_desc = desces;
		return;
	}
}

//迷宫房间是否为户外房间
void set_outdoors(int outd)
{
	if(!intp(outd))
		return;

	if(outd)
		is_outdoors = 1;
}

string query_owner()
{
	return owner;
}

//迷宫刷新
void set_maze_refresh(int m_refresh)
{
	if (intp(m_refresh) && m_refresh>=1)
		refresh_delay = m_refresh; 
}

/*	*** 以上是预设迷宫参数的接口函数 ***

		
		
		***************** 以下是创建迷宫的主函数 ************************


//	迷宫中的怪物和物件--	从原来的vrm_server中去除了这部分内容，
	一个好的迷宫，不可能用一个数组来写出NPC的分布，必须用一些较复杂的定义和
	判断来使其个性化，所以这里使用的方法是在调用时让inherit_room去继承一个和
	迷宫内容有关的maze-room，在这个文件里可以定义NPC/obj，定义valid_leave,
	add_action等等。
	也就是说，迷宫的文件包括
	1。迷宫创建文件 -- 定义迷宫大小，方位，基本描述，迷宫房间文件
	2。迷宫房间定义文件--迷宫房间的具体定义
	3。本文件
	
// 	创造迷宫房间，由 VIRTUAL_D 调用。*/

nomask object query_maze_room(string str)
{
	int idx,idx_owner,idx2,x,y,z,exits;
	object ob,me,o;
	string f,req_owner;
	
//  seteuid(ROOT_UID);
	seteuid(getuid());

//	log_file("debug.log", sprintf("\nstr=%s..\n", str));

//	if( previous_object() && (geteuid(previous_object()) != ROOT_UID) )
//		return 0;

//	log_file("debug.log", sprintf("\ncontinue..\n", str));


	if(!stringp(str) || str == "")		return 0;

	idx_owner = member_array('/', str);
	if(!sscanf(str[0..idx_owner-1],"%s",req_owner))
		return 0;
	else
		str=str[idx_owner+1..];

	
//	log_file("debug.log", sprintf("\nppl=%s,owner=%s,req_owner=%s\n", this_player()->query("id"),owner,req_owner));

	if (!owner)
		owner=req_owner;
	else if (req_owner != owner)	// request owner not this owner
	{
		o=find_player(req_owner);
		if (!o)
			return 0;	// Maze construct failed.
		if (o->query("private_mazer/maze"))
			ob=o->query("private_mazer/maze");
		else
		{
//			log_file("debug.log", sprintf("\n get new...\n", ob));
			ob=new(__DIR__"halloween");
			o->set("private_mazer/maze",ob);
//			log_file("debug.log", sprintf("\n - %O -\n", ob));
		}
//		log_file("debug.log", sprintf("\n ~ %O ~\n", ob));
		ob=ob->query_maze_room(req_owner+"/"+str);
		return ob;
	}

	if(!maze_built)	// 迷宫未建立
	{
		this_player()->set("private_mazer/maze",this_object());
		mark_ob = this_player();
	//	owner=mark_ob;
		create_maze();
	}
	if(!maze_built)		return 0;

//	log_file("debug.log", sprintf("\nowner = %s built a maze, string = %s.\n",owner,str));


	if(str == "entry")	// 迷宫入口房间
	{
		f = inherit_rooms[random(sizeof(inherit_rooms))];
                                               
		ob = new(f);
//		ob = load_object(f);
		if(!ob)	return 0;
		ob->set("virtual_room",1);
		ob->set("short",entry_short);
		ob->set("long",entry_desc);
		ob->set("owner",owner);
		ob->set("mark_ob",mark_ob);
		if (is_outdoors)	ob->set("outdoors",1);
//		ob->set(sprintf("exits/%s",link_entry_dir),link_entry_room);
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),mroom_fname(enter->x,enter->y,enter->z));
		ob->set("coor/x",link_entry_room_x);
		ob->set("coor/y",link_entry_room_y);
		ob->set("coor/z",link_entry_room_z);
		ob->set("no_fly",1);
		ob->set("entry_room",1);
		ob->setup_entry_room();

//		log_file("debug.log", sprintf("\nowner = %s built a maze, return ob = %O.\n",owner,ob));
		
		return ob;
	}

	if(str == "exit")	// 迷宫出口房间
	{
		f = inherit_rooms[random(sizeof(inherit_rooms))];

		ob = new(f);
		//ob = load_object(f);
		if(!ob)	return 0;
		ob->set("no_fly",1);
		ob->set("virtual_room",1);
		ob->set("short",exit_short);
		ob->set("long",exit_desc);
		ob->set("mark_ob",mark_ob);
		ob->set("owner",owner);
		if(is_outdoors)		ob->set("outdoors",1);
//		ob->set(sprintf("exits/%s",link_exit_dir),link_exit_room);
		ob->set(sprintf("exits/%s",entry_dir), mroom_fname(leave->x,leave->y,leave->z));
		switch (entry_dir) {
			case "east":	ob->set("coor/x",link_entry_room_x - l*s - 2*s);
					ob->set("coor/y",link_entry_room_y + (leave->y - enter->y)*s);
					ob->set("coor/z",link_entry_room_z);
					break;
			case "west":	ob->set("coor/x",link_entry_room_x + l*s +2*s);
					ob->set("coor/y",link_entry_room_y + (leave->y - enter->y)*s);
					ob->set("coor/z",link_entry_room_z);
					break;
			case "south":	ob->set("coor/x",link_entry_room_x + (leave->x - enter->x)*s);
					ob->set("coor/y",link_entry_room_y + m*s +2*s);
					ob->set("coor/z",link_entry_room_z);
					break;
			case "north":	ob->set("coor/x",link_entry_room_x + (leave->x - enter->x)*s);
					ob->set("coor/y",link_entry_room_y - m*s -2*s);
					ob->set("coor/z",link_entry_room_z);
					break;		
			case "up":	ob->set("coor/x",link_entry_room_x + (leave->x - enter->x)*s);
					ob->set("coor/y",link_entry_room_y + (leave->y - enter->y)*s);
					ob->set("coor/z",link_entry_room_z - h*s -2*s);
					break;		
			case "down":ob->set("coor/x",link_entry_room_x + (leave->x - enter->x)*s);
					ob->set("coor/y",link_entry_room_y + (leave->y - enter->y)*s);
					ob->set("coor/z",link_entry_room_z + h*s +2*s);
					break;		
		}
		ob->set("exit_room",1);
		ob->setup_exit_room();
		return ob;
	}

	idx = member_array('/', str);
	if( idx == -1 )
		return 0;

	

	if(!sscanf(str[0..idx-1],"%d",x))		return 0;

	idx2 = member_array('/', str[idx+1..]);
	if( idx2 == -1 )
		return 0;

	if(!sscanf(str[idx+1..idx+idx2],"%d",y))		return 0;
	if(!sscanf(str[idx+idx2+2..],"%d",z))		return 0;

	if( !exits = all[x][y][z] )		return 0;

	f = inherit_rooms[random(sizeof(inherit_rooms))];

	ob = new(f);
	//ob = load_object(f);
	if(!ob)
		return 0;

	ob->set("virtual_room",1);
	ob->set("no_fly",1);
	ob->set("mark_ob",mark_ob);
	ob->set("owner",owner);
	
//	根据入口坐标和迷宫大小来定义房间坐标
	switch (entry_dir) {
		case "east":	ob->set("coor/x",x*s-l*s+link_entry_room_x-s);
				ob->set("coor/y",y*s-to_int(m/2)*s + link_entry_room_y);
				ob->set("coor/z",link_entry_room_z);
				break;
		case "west":	ob->set("coor/x",x*s+link_entry_room_x+s);
				ob->set("coor/y",y*s-to_int(m/2)*s+link_entry_room_y);
				ob->set("coor/z",link_entry_room_z);
				break;
		case "south":	ob->set("coor/x",x*s-to_int(l/2)*s + link_entry_room_x);
				ob->set("coor/y",y*s+link_entry_room_y +s);
				ob->set("coor/z",link_entry_room_z);
				break;
		case "north":	ob->set("coor/x",x*s-to_int(l/2)*s + link_entry_room_x);
				ob->set("coor/y",y*s-m*s+link_entry_room_y-s);
				ob->set("coor/z",link_entry_room_z);
				break;
		case "up":	ob->set("coor/x",x*s-to_int(l/2)*s + link_entry_room_x);
				ob->set("coor/y",y*s-to_int(m/2)*s + link_entry_room_y);
				ob->set("coor/z",z*s-h*s+link_entry_room_z-s);
				break;
		case "down":	ob->set("coor/x",x*s-to_int(l/2)*s + link_entry_room_x);
				ob->set("coor/y",y*s-to_int(m/2)*s + link_entry_room_y);
				ob->set("coor/z",z*s+link_entry_room_z+s);
				break;
	}		
				

//	setting exits directions:
	if(exits&W)
		ob->set("exits/west",mroom_fname(x-1,y,z));
	if(exits&E)
		ob->set("exits/east",mroom_fname(x+1,y,z));
	if(exits&N)
		ob->set("exits/north",mroom_fname(x,y+1,z));
	if(exits&S)
		ob->set("exits/south",mroom_fname(x,y-1,z));
	if(exits&UP)
		ob->set("exits/up",mroom_fname(x,y,z+1));
	if(exits&D)
		ob->set("exits/down",mroom_fname(x,y,z-1));

	if( (x == enter->x) && (y == enter->y) && (z == enter->z))
		ob->set(sprintf("exits/%s",entry_dir),
			sprintf("%s/%s/entry",base_name(this_object()),owner));
	if( (x == leave->x) && (y == leave->y)  && (z == leave->z))
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),
			sprintf("%s/%s/exit",base_name(this_object()),owner));

	
	if(is_outdoors)		ob->set("outdoors",1);

//	指向迷宫房间定义文件来设定房间描述
	
	f->setup_room_desc(owner,ob,l,m,h,x,y,z);	
	
//	指向迷宫房间定义文件来设定怪物/物品	
	f->setup_npc_obj(owner,ob,l,m,h,x,y,z);
	f->setup_room_obj(owner,ob,l,m,h,x,y,z);
	
//	指向迷宫房间定义文件来设定物品描述
	
	return ob;
}





void create()
{
	set_inherit_room(__DIR__"halloween_room");
	set_maze_long(2+random(2),2+random(2),1+random(2));
	set_maze_spacing(1);
	set_maze_refresh(270);	// 每个maze生存3min.--> 4'30'' easy is fine :)

	set_entry_dir("north");

	set_link_entry_dir("down");
	set_link_entry_room("/d/fy/fysquare");
	set_link_entry_room_x(110);
	set_link_entry_room_y(0);
	set_link_entry_room_z(0);
	
	set_link_exit_dir("out");
	set_link_exit_room("/d/fy/fysquare");

	set_entry_short(MAG"南瓜仓底层"NOR);
	set_entry_desc("南瓜南瓜南瓜南瓜南瓜南瓜南瓜南瓜南瓜还是南瓜...\n");

	set_exit_short(MAG"南瓜仓顶阁"NOR);
	set_exit_desc("南瓜南瓜南瓜南瓜南瓜南瓜南瓜南瓜南瓜没错这里都是南瓜...\n");


	set_maze_room_short(MAG"古佛窟"NOR);
	set_maze_room_desc(@LONG
再往里去，就是小巴山传闻中神秘莫测的古佛窟。站在洞口看去，只见灰岩风
锈，貌不惊人，但据曾侥幸自佛窟中逃出性命的人说，窟内借万尊佛像之力布有奇
门阵法，能以五音五色乱人心脉，一进佛窟，就只见各种幻象层出不穷，定力稍有
不坚，便会迷失在异象之中。
LONG
);

}

/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
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


