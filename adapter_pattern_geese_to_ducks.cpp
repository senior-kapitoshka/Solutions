class GooseToIDuckAdapter:public IDuck
{
public:
    GooseToIDuckAdapter(Goose *g):g_(g) { }
    std::string Quack()override{
      return g_->Honk();
    }
    void Fly()override{
     g_->Fly();
    }
private:
  Goose* g_;
};

