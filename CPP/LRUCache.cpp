
class LRUCache{

    private:
        int cap;
        // key, iterator to the list element
        unordered_map <int, list<pair<int, int> >::iterator> m_map;
        // A list of key, value pair
        list<pair<int, int> > m_list;

    public:
        LRUCache(int capacity) {
            cap = capacity;
        }

        int get(int key) {
            if(m_map.find(key) == m_map.end()){
                return -1;
            }
            else{

                int value = m_map[key]->second;

                m_list.erase(m_map[key]);

                m_list.push_front(make_pair(key, value));

                m_map[key] = m_list.begin();

                return value;
            }
        }

        void set(int key, int value) {

            if(m_map.find(key) != m_map.end())
            {            
                m_list.erase(m_map[key]);
            }

            m_list.push_front(make_pair(key, value));

            m_map[key] = m_list.begin();

            // if reach the cap, remove the 
            if(m_map.size() == cap+1){
                auto endIter = m_list.end();
                endIter--;
                //erease from the map with the key. Notice: erase the key first, or will be invalid.
                //Notice: the problem here is, use m_list.end()->first. in which m_list.end() is not the last element.
                m_map.erase(endIter->first);

                m_list.pop_back();
            }
        }
};
