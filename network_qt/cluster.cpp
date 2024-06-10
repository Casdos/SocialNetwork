#include "cluster.h"

Cluster::Cluster() {}
void Cluster::addPerson(const People& p)
{
    peoples.push_back(p);
}
std::vector<Cluster> Cluster::hierarchicalClustering(Cluster peo)
{
    std::vector<Cluster> clusters;
    if (peo.peoples.empty()) return clusters;
    for (const auto& p : peo.peoples)
    {
        clusters.emplace_back(p);
    }
    while (clusters.size() > 1)
    {
        int minDistance = INT_MAX;
        std::pair<int, int> nearClusters;
        for (int i = 0; i < clusters.size(); i++)
        {
            qDebug()<<i;
            for (int j = i + 1; j < clusters.size(); j++)
            {
                int distance = INT_MAX;
                for (auto& p1 : clusters[i].peoples)
                {
                    for (auto& p2 : clusters[j].peoples)
                    {
                        double dist = p1.manhattanDistance(p2);
                        if(dist<distance)
                            distance=dist;
                    }
                }
                if (distance < minDistance) {
                    minDistance = distance;
                    nearClusters = { i,j };
                }
            }
        }
        if (minDistance > Threshold) break;

        clusters[nearClusters.first].peoples.insert(clusters[nearClusters.first].peoples.end(),
                                                    clusters[nearClusters.second].peoples.begin(),
                                                    clusters[nearClusters.second].peoples.end());

        // for(int x = 0;x<clusters[nearClusters.second].peoples.end()-clusters[nearClusters.second].peoples.begin();x++){
        //     clusters[nearClusters.first].peoples.push_back(clusters[nearClusters.second].peoples[x]);
        // }
        clusters.erase(clusters.begin() + nearClusters.second);

    }

    return clusters;
}
std::vector<std::vector<int>> generateMatrix01(int n, std::vector<Cluster> cluster) {
   std:: vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    // 定义聚类的数量
    int ClassNum = cluster.size();
    // i 表示矩阵行,j表示矩阵列
    for (int i = 0; i < n; ++i)
    {
        // block 表示i属于cluater的第几块
        int block = 0;
        int sum = 0;
        for (int k = 0; k < ClassNum; k++) {
            sum += cluster[k].peoples.size();
            if (i < sum) { block = k; break; }
        }

        for (int j = i; j < sum; ++j) {
            double distance = cluster[block].peoples[i-sum+cluster[block].peoples.size()].manhattanDistance(cluster[block].peoples[j-sum+cluster[block].peoples.size()]);
            if (distance <= cluster[block].Threshold) {
                matrix[i][j] = 1;
                matrix[j][i] = 1; // 因为矩阵是对称的，所以也要更新j到i的关系
            }
        }
    }
    return matrix;
}
void Cluster::load(std::string filepath)
{
    QString qFilePath = QString::fromStdString(filepath);
    QFile file(qFilePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug()<<"error";
        ;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        People p;
        p.name = fields[0].trimmed().toStdString();
        p.age = fields[1].trimmed().toInt();
        p.sex = p.str2sex(fields[2].trimmed().toStdString());
        p.job = p.str2job(fields[2].trimmed().toStdString());
        peoples.push_back(p);
    }
    file.close();

}
